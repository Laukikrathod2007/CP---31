class animal{
    void sound(){
        System.out.println("Animal makes a sound");
    }
    class dog extends animal{
        void sound(){
            System.out.println("Dog barks");
        }
    }

    public class MethodOverriding{
        public static void main(String[] args) {
            animal a = new animal();
            a.sound();

            dog d = new dog();
            d.sound();
        }
    }
}