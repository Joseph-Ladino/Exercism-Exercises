class ReverseString {

    String reverse(String inputString) {
        String out = "";
        for(int i = inputString.length() - 1; i >= 0 ; i--) {
            out += inputString.charAt(i);
        }

        return out;
    }
  
}
