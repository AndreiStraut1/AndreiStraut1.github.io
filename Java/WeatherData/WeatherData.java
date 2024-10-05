package WeatherData;

import java.io.*;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.List;

class processData {
    List<String> filePaths = new ArrayList<>();
    double minTemp = 999.99;
    int coldestTempIndex = -1;
    double minHumidity = 999.99;
    int lowestHumidityIndex = -1;

    public List<String[]> readCSV(String csvFile) {
        List<String[]> data = new ArrayList<>();
        BufferedReader reader = null;
        String line = "";

        try {
            reader = new BufferedReader(new FileReader(csvFile));
            while ((line = reader.readLine()) != null) {
                String[] values = line.split(",");
                data.add(values);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                reader.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return data;
    }

    public String coldestHourInFile(String fileName) {
        List<String[]> fileContent = readCSV(fileName);
        for (int i = 1; i < fileContent.size(); i++) {
            String row[] = fileContent.get(i);
            double temperature = Double.parseDouble(row[1]);

            if (temperature < minTemp) {
                minTemp = temperature;
                coldestTempIndex = i;
            }
        }
        return "Coldest temperature was " + fileContent.get(coldestTempIndex)[1] + " at "
                + fileContent.get(coldestTempIndex)[13];

    }

    public void addFileSources(String path) {
        filePaths.add(path);
    }

    public String fileWithColdestTemperature() {
        int coldFileIndex = -1;
        double momentaryMinimum = 999.99;
        for (int i = 0; i < filePaths.size(); i++) {
            String filePath = filePaths.get(i);
            coldestHourInFile(filePath);
            if (minTemp < momentaryMinimum) {
                momentaryMinimum = minTemp;
                coldFileIndex = i;
            }
        }

        System.out.println("Coldest day was in file " + filePaths.get(coldFileIndex));
        System.out.println("Coldest temperature on that day was " + minTemp);
        System.out.println("All the Temperatures on the coldest day were: ");
        List<String[]> fileContent = readCSV(filePaths.get(coldFileIndex));
        for (int i = 1; i < fileContent.size(); i++) {
            System.out.print(fileContent.get(i)[13] + " " + fileContent.get(i)[1]);
            System.out.println();
        }
        return filePaths.get(coldFileIndex);
    }

    public String lowestHumidityInFile(String fileName) {
        List<String[]> fileContent = readCSV(fileName);
        for (int i = 1; i < fileContent.size(); i++) {
            String row[] = fileContent.get(i);
            double humidity = Double.parseDouble(row[3]);
            if (humidity < minHumidity) {
                minHumidity = humidity;
                lowestHumidityIndex = i;
            }
        }
        return "Lowest humidity was " + fileContent.get(lowestHumidityIndex)[3] + " at "
                + fileContent.get(lowestHumidityIndex)[13];
    }

    public String lowestHumidityInManyFiles() {
        int lowHumFileIndex = -1;
        double momentaryMinimum = 999.99;
        for (int i = 0; i < filePaths.size(); i++) {
            String filePath = filePaths.get(i);
            lowestHumidityInFile(filePath);
            if (minHumidity < momentaryMinimum) {
                momentaryMinimum = minHumidity;
                lowHumFileIndex = i;
            }
        }

        List<String[]> fileContent = readCSV(filePaths.get(lowHumFileIndex));
        return "Lowest humidity was " + fileContent.get(lowestHumidityIndex)[3] + " at "
                + fileContent.get(lowestHumidityIndex)[13];
    }

    public String averageTemperatureInFile(String fileName) {
        double avg = 0.0;
        List<String[]> fileContent = readCSV(fileName);
        for (int i = 1; i < fileContent.size(); i++) {
            String row[] = fileContent.get(i);
            double temperature = Double.parseDouble(row[1]);
            avg += temperature;
        }
        avg = avg / (fileContent.size() - 1);
        return "Average temperature in file is " + avg;
    }

    public Double averageTemperatureWithHighHumidityInFile(String fileName, double value) {
        double avgTempWithHighHum = 0.0;
        int cnt = 0;
        List<String[]> fileContent = readCSV(fileName);
        for (int i = 1; i < fileContent.size(); i++) {
            String row[] = fileContent.get(i);
            double humidity = Double.parseDouble(row[3]);
            if (humidity >= value) {
                double temperature = Double.parseDouble(row[1]);
                cnt++;
                avgTempWithHighHum += temperature;
            }
        }
        avgTempWithHighHum = avgTempWithHighHum / cnt;
        return avgTempWithHighHum;
    }

}

public class WeatherData {
    public static void main(String[] args) {
        processData pData = new processData();

        Scanner scanner = new Scanner(System.in);

        System.out.println("What method do you want to call?");
        System.out.println("1- coldest hour in file");
        System.out.println("2- file with coldest temperature");
        System.out.println("3- lowest humidity in file");
        System.out.println("4- lowest humidity in many files");
        System.out.println("5- average temperature in file");
        System.out.println("6- average temperature with humidity in file");
        System.out.print("Enter your choice: ");

        int choice = scanner.nextInt();

        File mainDir = new File("Java/WeatherData/nc_weather");
        System.out.println("From which file?");
        System.out.print("Enter year: ");
        int year = scanner.nextInt();
        File thisFile = new File(mainDir + "/" + year);
        System.out.println("This year has " + thisFile.list().length + " days recorded");
        String[] csvFiles = thisFile.list();

        switch (choice) {
            case 1:
                System.out.print("Enter the day (1-" + thisFile.list().length + "): ");
                int dayNr = scanner.nextInt() - 1;
                System.out.println(pData.coldestHourInFile(thisFile + "/" + csvFiles[dayNr]));
                break;

            case 2:
                System.out.println("Enter the first day: ");
                int first = scanner.nextInt() - 1;
                System.out.println("Enter the last day: ");
                int last = scanner.nextInt();
                for (int i = first; i < last; i++) {
                    pData.addFileSources(thisFile + "/" + csvFiles[i]);
                }
                pData.fileWithColdestTemperature();
                break;

            case 3:
                System.out.print("Enter the day (1-" + thisFile.list().length + "): ");
                int selectedDay = scanner.nextInt() - 1;
                System.out.println(pData.lowestHumidityInFile(thisFile + "/" + csvFiles[selectedDay]));
                break;

            case 4:
                System.out.println("Enter the first day: ");
                int start = scanner.nextInt() - 1;
                System.out.println("Enter the last day: ");
                int end = scanner.nextInt();
                for (int i = start; i < end; i++) {
                    pData.addFileSources(thisFile + "/" + csvFiles[i]);
                }
                System.out.println(pData.lowestHumidityInManyFiles());
                break;

            case 5:
                System.out.print("Enter the day (1-" + thisFile.list().length + "): ");
                int inputDay = scanner.nextInt() - 1;
                System.out.println(pData.averageTemperatureInFile(thisFile + "/" + csvFiles[inputDay]));
                break;

            case 6:
                System.out.print("Enter the day (1-" + thisFile.list().length + "): ");
                int inputedDay = scanner.nextInt() - 1;
                System.err.print("Enter the minimum humidity value: ");
                double minHumVal = scanner.nextDouble();
                double result = pData.averageTemperatureWithHighHumidityInFile(thisFile + "/" + csvFiles[inputedDay],
                        minHumVal);
                if (result > 0.0) {
                    System.out.println("Average Temp when high Humidity is " + result);
                }
                else {
                    System.out.println("No temperatures with that humidity");
                }

                break;

            default:
                System.out.println("Not a valid choice!");
                break;
        }
        scanner.close();
    }
}
