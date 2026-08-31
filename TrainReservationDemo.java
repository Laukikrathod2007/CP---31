class TrainReservation {

    private int availableTickets;

    // Constructor
    TrainReservation(int tickets) {
        availableTickets = tickets;
    }

    // Synchronized method for booking tickets
    public synchronized void bookTicket(String userName, int numberOfTickets) {

        System.out.println(userName + " is trying to book "
                + numberOfTickets + " ticket(s).");

        if (availableTickets >= numberOfTickets) {

            System.out.println("Tickets available: " + availableTickets);

            try {
                Thread.sleep(500);
            } catch (InterruptedException e) {
                System.out.println(e);
            }

            availableTickets = availableTickets - numberOfTickets;

            System.out.println("Booking successful for " + userName);
            System.out.println("Tickets booked: " + numberOfTickets);
            System.out.println("Tickets remaining: " + availableTickets);
            System.out.println("--------------------------------");
        } 
        else {
            System.out.println("Sorry " + userName
                    + ", insufficient tickets available.");
            System.out.println("Tickets available: " + availableTickets);
            System.out.println("--------------------------------");
        }
    }
}


// User thread
class User extends Thread {

    private TrainReservation reservation;
    private String userName;
    private int numberOfTickets;

    User(TrainReservation reservation, String userName,
         int numberOfTickets) {

        this.reservation = reservation;
        this.userName = userName;
        this.numberOfTickets = numberOfTickets;
    }

    public void run() {
        reservation.bookTicket(userName, numberOfTickets);
    }
}


// Main class
public class TrainReservationDemo {

    public static void main(String[] args) {

        // Shared pool containing 5 tickets
        TrainReservation reservation = new TrainReservation(5);

        // Multiple users
        User user1 = new User(reservation, "User-1", 2);
        User user2 = new User(reservation, "User-2", 1);
        User user3 = new User(reservation, "User-3", 2);
        User user4 = new User(reservation, "User-4", 1);

        // Start threads
        user1.start();
        user2.start();
        user3.start();
        user4.start();
    }
}