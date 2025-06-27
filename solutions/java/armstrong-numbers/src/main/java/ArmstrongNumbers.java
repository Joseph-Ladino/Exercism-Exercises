class ArmstrongNumbers {

    boolean isArmstrongNumber(int numberToCheck) {

        String s = Integer.toString(numberToCheck);
        int exp = s.length();

        for(int i = 0; i < exp; i++)
            numberToCheck -= Math.pow(s.charAt(i) - '0', exp);        

        return numberToCheck == 0;
    }

}
