public class TextAnalyzer {
    
    public TextAnalyzer() {
        // no variables to construct
    }

    public int countVowels(String input) {

        int counter = 0;

        // iterate through each letter of a string
        for (int i = 0; i < input.length(); i++) {

            switch (input.charAt(i)) {
                case 'A':
                case 'a':
                case 'E':
                case 'e':
                case 'I':
                case 'i':
                case 'O':
                case 'o':
                case 'U':
                case 'u':
                    counter++;
                    break;
                default:
                    break;
            }

        }

        return counter;
    }

    public static void main(String[] args) {
        TextAnalyzer ta1 = new TextAnalyzer();
        System.out.println(ta1.countVowels("Hello"));
        System.out.println(ta1.countVowels("Excited for you!"));
    }
}