import java.util.Scanner;

class ScientificCalculator {

    void calculate(int a, int b) {
        System.out.println("Addition = " + (a + b));
    }

    void calculate(int a, int b, char operation) {
        if (operation == '-') {
            System.out.println("Subtraction = " + (a - b));
        } else {    
            System.out.println("Invalid Operation");
        }
    }

    void calculate(double angle, String operation) {
        double radians = Math.toRadians(angle);

        switch (operation.toLowerCase()) {
            case "sin":
                System.out.println("sin(" + angle + ") = " + Math.sin(radians));
                break;

            case "cos":
                System.out.println("cos(" + angle + ") = " + Math.cos(radians));
                break;

            case "tan":
                System.out.println("tan(" + angle + ") = " + Math.tan(radians));
                break;

            case "log":
                if (angle > 0)
                    System.out.println("log(" + angle + ") = " + Math.log10(angle));
                else
                    System.out.println("Logarithm is undefined.");
                break;

            default:
                System.out.println("Invalid Operation");
        }
    }

    void calculate(int[][] A, int[][] B) {

        int rows = A.length;
        int cols = A[0].length;

        int[][] result = new int[rows][cols];

        System.out.println("\nMatrix Addition Result:");

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[i][j] = A[i][j] + B[i][j];
                System.out.print(result[i][j] + "\t");
            }
            System.out.println();
        }
    }
}

public class MethodOverloadingDemo {

    public static void main(String[] args) {

        ScientificCalculator sc = new ScientificCalculator();

        System.out.println("Integer Operations:");
        sc.calculate(20, 10);         // Addition
        sc.calculate(20, 10, '-');    // Subtraction

        System.out.println("\nScientific Operations:");                {7, 8}
        };
wefbskdfhjKdn cm,SD
        sc.calculate(matrix1, matrix2);
    }
}