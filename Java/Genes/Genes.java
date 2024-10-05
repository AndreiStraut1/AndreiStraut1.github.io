package Genes;

import java.lang.String;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

class Part1 {
    public String readFile(String filePath) throws IOException {
        StringBuilder dna = new StringBuilder();
        BufferedReader reader = new BufferedReader(new FileReader(filePath));
        String line;
        while ((line = reader.readLine()) != null) {
            dna.append(line.trim());
        }
        reader.close();
        return dna.toString();
    }

    public int findStopCodon(String dna, int startIndex, String stopCodon) {
        int currIndex = dna.indexOf(stopCodon, startIndex + 3);
        while (currIndex != -1) {
            if ((currIndex - startIndex) % 3 == 0) {
                return currIndex;
            } else {
                currIndex = dna.indexOf(stopCodon, currIndex + 1);
            }
        }
        return dna.length();
    }

    public String findGene(String dna, int start) {
        int startIndex = dna.indexOf("ATG", start);
        if (startIndex == -1) {
            return "";
        }
        int taaIndex = findStopCodon(dna, startIndex, "TAA");
        int tagIndex = findStopCodon(dna, startIndex, "TAG");
        int tgaIndex = findStopCodon(dna, startIndex, "TGA");

        int minIndex = Math.min(taaIndex, Math.min(tagIndex, tgaIndex));

        if (minIndex == dna.length()) {
            return "";
        }
        return dna.substring(startIndex, minIndex + 3);
    }

    public ArrayList<String> getAllGenes(String dna) {
        ArrayList<String> genes = new ArrayList<>();
        int startIndex = 0;
        while (true) {
            String gene = findGene(dna, startIndex);
            if (gene.isEmpty()) {
                break;
            }
            genes.add(gene);
            startIndex = dna.indexOf(gene, startIndex) + gene.length();
        }
        return genes;
    }

    public void testGetAllGenes(String dna) {
        System.out.println("Testing getAllGenes with DNA: " + dna);
        ArrayList<String> genes = getAllGenes(dna);
        for (String gene : genes) {
            System.out.println("Gene found: " + gene);
        }
    }
}

class Part2 {
    public float cgRatio(String dna) {
        int count = 0;
        for (int i = 0; i < dna.length(); i++) {
            char c = dna.charAt(i);
            if (c == 'C' || c == 'G') {
                count++;
            }
        }
        return (float) count / dna.length();
    }

    public int countCTG(String dna) {
        int count = 0;
        int index = dna.indexOf("CTG");
        while (index != -1) {
            count++;
            index = dna.indexOf("CTG", index + 3);
        }
        return count;
    }

    public void testCgRatioAndCountCTG(String dna) {
        System.out.println("Testing cgRatio with DNA: " + dna);
        System.out.println("CG Ratio: " + cgRatio(dna));

        System.out.println("Testing countCTG with DNA: " + dna);
        System.out.println("CTG Count: " + countCTG(dna));
    }
}

class Part3 {
    public void processGenes(ArrayList<String> genes) {
        int countLongerThan60 = 0;
        int countHighCgRatio = 0;
        int longestGeneLength = 0;

        for (String gene : genes) {
            if (gene.length() > 60) {
                System.out.println("Gene longer than 60 characters: " + gene);
                countLongerThan60++;
            }

            float cgRatio = cgRatio(gene);
            if (cgRatio > 0.35) {
                System.out.println("Gene with CG ratio higher than 0.35: " + gene);
                countHighCgRatio++;
            }

            if (gene.length() > longestGeneLength) {
                longestGeneLength = gene.length();
            }
        }

        System.out.println("Number of genes longer than 60 characters: " + countLongerThan60);
        System.out.println("Number of genes with CG ratio higher than 0.35: " + countHighCgRatio);
        System.out.println("Length of the longest gene: " + longestGeneLength);
    }

    public float cgRatio(String dna) {
        int count = 0;
        for (int i = 0; i < dna.length(); i++) {
            char c = dna.charAt(i);
            if (c == 'C' || c == 'G') {
                count++;
            }
        }
        return (float) count / dna.length();
    }

    public void testProcessGenes(ArrayList<String> genes) {
        processGenes(genes);
    }
}

public class Genes {
    public static void main(String[] args) {
        Part1 part1 = new Part1();
        Part2 part2 = new Part2();
        Part3 part3 = new Part3();
        
        try {
            // Reading DNA from file
            String dna = part1.readFile("Java/Genes/brca1line.txt");
            dna = dna.toUpperCase();

            part1.testGetAllGenes(dna);

            part2.testCgRatioAndCountCTG(dna);

            ArrayList<String> genes = part1.getAllGenes(dna);
            part3.testProcessGenes(genes);

        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
        }
    }
}
