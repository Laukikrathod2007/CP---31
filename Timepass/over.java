public class MathOperations{
    int add(int a, int b){
        return a + b;
    }
    int add(int a, int b, int c){
        return a + b + c;
    }
    public static void main(String[] args) {
        MathOperations obj = new MathOperations();
        System.out.println("Sum of 2 numbers: " + obj.add(5, 10));
        System.out.println("Sum of 3 numbers: " + obj.add(5, 10, 15));
    }
}