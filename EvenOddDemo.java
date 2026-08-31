class EvenThread extends Thread {

    public void run() {
        for (int i = 2; i <= 20; i += 2) {
            System.out.println("Even Thread: " + i);

            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}

class OddThread extends Thread {

    public void run() {
        for (int i = 1; i <= 19; i += 2) {
            System.out.println("Odd Thread: " + i);

            try {
                Thread.sleep(100);
            } catch (InterruptedException e) {
                System.out.println(e);
            }
        }
    }
}

public class EvenOddDemo {

    public static void main(String[] args) {

        EvenThread even = new EvenThread();
        OddThread odd = new OddThread();

        even.start();
        odd.start();
    }
}