package Shape;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

class Point {
    double x, y;

    Point(double x, double y) {
        this.x = x;
        this.y = y;
    }

    public double distanceTo(Point other) {
        return Math.sqrt(Math.pow(this.x - other.x, 2) + Math.pow(this.y - other.y, 2));
    }

}

class Shape {
    ArrayList<Point> points;
    ArrayList<Double> distances;

    Shape() {
        points = new ArrayList<>();
        distances = new ArrayList<>();
    }

    public void addPoint(Point point) {
        points.add(point);
    }

    public void calculateDistances() {
        distances.clear();
        for (int i = 0; i < points.size(); i++) {
            Point currentPoint = points.get(i);
            Point otherPoint = points.get((i + 1) % points.size());
            distances.add(currentPoint.distanceTo(otherPoint));
        }
    }

    public double getPerimeter() {
        double perimeter = 0;

        calculateDistances();

        for (int i = 0; i < distances.size(); i++) {

            perimeter += distances.get(i);

            System.out.println("Line from point " + i + " to point " + (i + 1) + " has length: " + distances.get(i));
        }

        return perimeter;
    }

    public double getAverageLength() {
        double averageLength = 0;
        calculateDistances();
        
        averageLength = this.getPerimeter() / distances.size();

        return averageLength;
    }

    public double getLargestX() {
        double largestX = Double.NEGATIVE_INFINITY;
        for (int i = 0; i < points.size(); i++) {
            double currentX = points.get(i).x;
            if (currentX > largestX) {
                largestX = currentX;
            }
        }

        return largestX;
    }

    public double getLargestSide() {
        double largestSide = 0;

        for (int i = 0; i < distances.size(); i++) {
            if (distances.get(i) > largestSide) {
                largestSide = distances.get(i);
            }
        }

        return largestSide;
    }
}

public class ShapePerimeter {
    private static ArrayList<Shape> shapes = new ArrayList<>();
    private static String fileWithLargestPerimeter = null;
    private static double largestPerimeter = 0;

    public static void main(String[] args) {

        String[] filenames = { "Java/Shape/shape1.txt", "Java/Shape/shape2.txt", "Java/Shape/shape3.txt" };

        for (String filename : filenames) {
            System.out.println("Processing file: " + filename);

            Shape shape = new Shape();

            try (BufferedReader br = new BufferedReader(new FileReader(filename))) {
                String line;
                int numPoints = Integer.parseInt(br.readLine().trim());

                for (int i = 0; i < numPoints; i++) {
                    line = br.readLine();
                    if (line != null) {
                        String[] parts = line.trim().split("\\s+");
                        double x = Double.parseDouble(parts[0]);
                        double y = Double.parseDouble(parts[1]);
                        shape.addPoint(new Point(x, y));
                    }
                }
                shapes.add(shape);

                double perimeter = shape.getPerimeter();
                System.out.println("Shape " + shapes.size() + "'s perimeter is: " + perimeter);
                System.out.println("Shape " + shapes.size() + "'s average length is: " + shape.getAverageLength());
                System.out.println("Shape " + shapes.size() + "'s largest X is: " + shape.getLargestX());
                System.out.println("Shape " + shapes.size() + "'s largest side is: " + shape.getLargestSide());

                if (perimeter > largestPerimeter) {
                    largestPerimeter = perimeter;
                    fileWithLargestPerimeter = filename;
                }

            } catch (IOException e) {
                System.err.println("Error reading the file " + filename + ": " + e.getMessage());
            }

            System.out.println(); 

            
        }
        
        if (fileWithLargestPerimeter != null) {
            System.out.println("File with the largest perimeter: " + fileWithLargestPerimeter);
            System.out.println("Largest perimeter: " + largestPerimeter);
        } else {
            System.out.println("No files were processed.");
        }
    }
}