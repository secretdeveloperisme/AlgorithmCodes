import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class FundamentalAlgorithms {
    public static String amendTheSentence(String s) {
        String result = "";
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) <= 90 && s.charAt(i) >= 65)
                result += " " + (char) (s.charAt(i) + 32);
            else
                result += s.charAt(i);
        }
        return result.trim();
    }

    public static boolean checkPalindrome(String inputString) {
        boolean flag = true;
        int len = inputString.length();
        for (int i = 0; i < (len / 2); i++) {
            if (inputString.charAt(i) != inputString.charAt(len - 1 - i)) {
                flag = false;
                break;
            }
        }
        return flag;
    }

    // this is suitable for 2 or 3 blank space
    public static String formatString(String input) {
        input = input.trim();
        while (input.contains("  ")) {
            input = input.replace("  ", " ");
        }
        while (input.contains("   ")) {
            input = input.replace("   ", " ");
        }
        return input;
    }

    public static boolean isTandemRepeat(String inpuString) {
        int len = inpuString.length();
        if (len % 2 != 0)
            return false;
        for (int i = 0; i < len / 2; i++) {
            if (inpuString.charAt(i) != inpuString.charAt(len / 2 + i))
                return false;
        }
        return true;
    }

    public static String truncateString(String s) {
        boolean flag = true;
        while (flag && (s.length() > 0)) {
            System.out.println(s);
            flag = false;
            if ((s.charAt(0) - '0') % 3 == 0) {
                s = s.substring(1);
                flag = true;
            } else if ((s.charAt(s.length() - 1) - '0') % 3 == 0) {
                flag = true;
                s = s.substring(0, s.length() - 2);
            }

            else if (((s.charAt(0) - '0') + (s.charAt(s.length() - 1) - 96)) % 3 == 0) {
                s = s.substring(1, s.length() - 2);
                flag = true;
            }

        }

        return s;
    }

    public boolean checkStringCrossover(String a, String b, String result) {
        for (int i = 0; i < a.length(); i++) {
            if ((a.charAt(i) != result.charAt(i)) && (b.charAt(i) != result.charAt(i)))
                return false;
        }
        return true;
    }

    public int stringsCrossover(String[] inpuStrings, String result) {
        int count = 0;
        for (int i = 0; i < (inpuStrings.length - 1); i++) {
            for (int j = i + 1; j < inpuStrings.length; j++) {
                if (checkStringCrossover(inpuStrings[i], inpuStrings[j], result))
                    count++;
            }
        }
        return count;
    }
    public static String toStringNumber(int n){
        String s="";
        while(n>0){
            s=(char)(n%10+'0')+s;
            n/=10;
        }
        return s;
    }
    public static String lineEncoding(String s){
        s=s+" ";
        String result="";
        int count=1;
        for(int i=0;i<s.length()-1;i++){
            if(s.charAt(i)==s.charAt(i+1))
                count++;
            else{
                if(count>1)
                    result+=toStringNumber(count);
                result+=s.charAt(i);
                count=1;
                    
            }
        }
        return result;
    }
    public static String numberToText(int n) {
		int size = String.valueOf(n).trim().length();
		byte[] numberArray = new byte[size];
		int index = 0;
		int copyN = n;
		while(copyN > 0) {
			byte a = (byte)(copyN % 10);
			copyN /= 10;
			numberArray[index] = a;
			index ++;
		}
		for (int i = 0; i < size/2; i++) {
			byte temp = numberArray[i];
			numberArray[i] = numberArray[size - 1 - i];
			numberArray[size - 1 - i] = temp;
		}
		String[] texts = {"khong", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin"};
		String[] units = {"ty", "tram", "muoi", "trieu", "tram", "muoi", "ngan", "tram", "muoi", ""};
		int lengthOfTexts = texts.length;
		String result = "";
		String[] numberTexts = new String[size];
		for(int i = 0;i < size;i++) {
			numberTexts[i] = texts[numberArray[i]]; 
		}
		//remove tail zero
		for(int i = size - 1, j = 0; i >= 0; i--) {
			if(numberArray[i] == 0) {
				numberTexts[i] = "";
				units[lengthOfTexts-1-j] = "";
				j++;
			}
			else {
				break;
			}
		}
		// remove 10 000 000 
		for(int i = 0; i < size;i++) {	
			result += numberTexts[i] + " " + units[10 - size + i] +" ";
		}	
		List listNumbers =List.of(0,1,2,3,4,5,6,7,8,9);
		if(size == 5 && (listNumbers.indexOf((float)n/10000) != -1)) {
			result += "ngan";
		}
		else
			if(size == 6 &&(listNumbers.indexOf((float)n/100000) != -1)) {
				result += "ngan";
			}
			else
				if(size == 8 && (listNumbers.indexOf((float)n/10000000) != -1)) {
					result += "trieu";
				}
				else
					if(size == 9 && (listNumbers.indexOf((float)n/100000000) != -1)) {
						result += "trieu";
					}
		result = result.replace("mot muoi", "muoi");
		Pattern pattern = Pattern.compile("\\w+");
		Matcher matcher = pattern.matcher(result);
		result = "";
		while(matcher.find()) {
			result += matcher.group() +" ";
		}
		return result;
    }
    public static void main(String[] args) {
        // System.out.println(amendTheSentence("CodesignalIsAwesome"));
        // System.out.println(checkPalindrome("acbca"));
        // System.out.println(formatString("abc a aa a a "));
        // System.out.println(isTandemRepeat("tandemtandem"));
        // System.out.println(truncateString("312248"));
        // System.out.println(
        // new FundamentalAlgorithms().stringsCrossover(new String[] { "abc", "aaa", "aba", "bab" }, "bbb"));
        // System.out.println(lineEncoding("aabbbc"));
    	System.out.println(numberToText(Integer.parseInt(args[0])));
    }
}
