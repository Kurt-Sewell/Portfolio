public class ProjectEuler {
    public static void main(String args[]){
        System.out.println(Problem3());
    }

    static long Problem3(){
        long num = 600851475143L;
        long fact = 1;
        long score = 0;
        while(fact < num){
            if(num % fact == 0){  // Checks to see whether fact is a factor of num
                for(int i = 2; i < fact / 2; i++){
                    if(fact % i == 0){ // Checks if fact is divisible by any other number
                        break;
                    }
                    else{
                        System.out.println(fact + "is a Prime Number");
                        score = fact;
                        return score;
                    }
                }
            }
        }
        return score;
    }

    static int Problem2(){
        int sum = 0;
        int fib = 1;
        int pre = 1;
        int hold = 0;
        while(fib < 4000000){
            if(fib % 2 == 0){
                sum += fib;
            }
            hold = fib;
            fib += pre;
            pre = hold;
        }
        return sum;
    }

    static int Problem1(){
        int score = 0;
        for(int i = 0; i < 1000; i++){
            if(i % 3 == 0){
                score += i;
            }
            else if(i % 5 == 0){
                score += i;
            }
        }
        return score;
    }
}

