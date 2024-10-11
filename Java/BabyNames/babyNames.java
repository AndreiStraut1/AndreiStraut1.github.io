package BabyNames;

import java.io.*;

class processData {
    public void totalBirths(String csvFile) {
        BufferedReader reader = null;
        String line = "";
        int totalNr = 0;
        int girlsNr = 0;
        int boysNr = 0;

        try {
            reader = new BufferedReader(new FileReader(csvFile));
            while ((line = reader.readLine()) != null) {
                String[] values = line.split(",");
                totalNr += Integer.valueOf(values[2]);
                if (values[1].equals("M")) {
                    boysNr += Integer.valueOf(values[2]);
                } else {
                    girlsNr += Integer.valueOf(values[2]);
                }
            }
            System.out.println("Total number of births: " + totalNr);
            System.out.println("Number of boys that were born: " + boysNr);
            System.out.println("Number of girls that were born: " + girlsNr);
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                reader.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public int getRank(int year, String name, String gender) {
        String fileName = "Java/BabyNames/us_babynames/testing/yob" + year + "short.csv";
        BufferedReader reader = null;
        String line = "";
        int rankG = 0;
        int rankB = 0;
        try {
            reader = new BufferedReader(new FileReader(fileName));
            while ((line = reader.readLine()) != null) {
                String[] values = line.split(",");
                if (values[1].equals(gender)) {
                    rankG++;
                    if (values[0].equals(name)) {
                        return rankG;
                    }
                }

                if (values[1].equals(gender)) {
                    rankB++;
                    if (values[0].equals(name)) {
                        return rankB;
                    }
                }
            }
            return -1;
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            try {
                reader.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        return -1;
    }

    String getName(int year, int rank, String gender) {
        String fileName = "Java/BabyNames/us_babynames/testing/yob" + year + "short.csv";
        BufferedReader reader = null;
        String line = "";
        int rankG = 0;
        int rankB = 0;
        try {
            reader = new BufferedReader(new FileReader(fileName));
            while ((line = reader.readLine()) != null) {
                String[] values = line.split(",");
                if (values[1].equals(gender)) {
                    rankG++;
                    if (rankG == rank) {
                        return values[0];
                    }
                }

                if (values[1].equals(gender)) {
                    rankB++;
                    if (rankB == rank) {
                        return values[0];
                    }
                }
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
        return "NO NAME";
    }

    void whatIsNameInYear(String name, int year, int newYear, String gender) {
        int rank = getRank(year, name, gender);
        String newName = getName(newYear, rank, gender);
        System.out.println(name + " born in " + year + " would be " + newName + " in " + newYear + ".");
    }

    int yearOfHighestRank(String name, String gender) {
        int maxRank = Integer.MAX_VALUE;
        int curRank = 0;
        int year = 0;
        for (int i = 2012; i <= 2014; i++) {
            curRank = getRank(i, name, gender);
            if (curRank < maxRank) {
                maxRank = curRank;
                year = i;
            }
        }
        return year;
    }

    Double getAverageRank(String name, String gender) {
        Double avgRank = 0.0;
        int currRank = 0;
        int index = 0;
        for (int i = 2012; i <= 2014; i++) {
            currRank = getRank(i, name, gender);
            avgRank += currRank;
            index++;
        }
        avgRank /= index;
        return avgRank;
    }

    int getTotalBirthsRankedHigher(int year, String name, String gender) {
        String fileName = "Java/BabyNames/us_babynames/testing/yob" + year + "short.csv";
        BufferedReader reader = null;
        String line = "";
        int rank = getRank(year, name, gender);
        int curRank = 0;
        int totalBirths = 0;
        if (rank == 1) {
            return 0;
        } else {
            try {
                reader = new BufferedReader(new FileReader(fileName));
                while ((line = reader.readLine()) != null) {
                    String[] values = line.split(",");
                    if (values[1].equals(gender)) {
                        curRank++;
                        if (curRank < rank) {
                            totalBirths += Integer.valueOf(values[2]);
                        }
                    }
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
        }
        return totalBirths;
    }
}

public class babyNames {
    public static void main(String[] args) {
        processData pd = new processData();
        //String fileName = "Java/BabyNames/us_babynames/testing/yob2012short.csv";

        // pd.totalBirths(fileName);
        // System.out.println(pd.getRank(2012, "Andrei", "F"));
        // System.out.println(pd.getName(2012, 6, "F"));
        // pd.whatIsNameInYear("Mason", 2012, 2014, "M");
        // System.out.println(pd.yearOfHighestRank("Mason", "M"));
        //System.out.println(pd.getAverageRank("Jacob", "M"));
        System.out.println(pd.getTotalBirthsRankedHigher(2012, "Ava", "F"));
    }
}
