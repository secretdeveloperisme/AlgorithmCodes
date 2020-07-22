import sun.tools.java.AmbiguousMember;

public class FundamentalAlgorithms{
    public static String amendTheSentence(String s) {
        String result="";
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)<=90&&s.charAt(i)>=65)
                result+=" "+(char)(s.charAt(i)+32);
            else 
                result+=s.charAt(i);
        }
        return result.trim();
    }
    public static boolean checkPalindrome(String inputString){
        boolean flag=true;
        int len=inputString.length();
        for(int i=0;i<(len/2);i++){
            if(inputString.charAt(i)!=inputString.charAt(len-1-i))
            {
                flag=false;
                break;
            }
        }
        return flag;
    }
    //this is suitable for 2 or 3 blank space
    public static String formatString(String input){
        input=input.trim();
        while(input.contains("  ")){
          input =  input.replace("  ", " ");
        }
        while(input.contains("   ")){
          input =  input.replace("   ", " ");
        }
        return input;
    }
    public static boolean isTandemRepeat(String inpuString){
        int len=inpuString.length();
        if(len%2!=0)
            return false;
        for(int i=0;i<len/2;i++){
            if(inpuString.charAt(i)!=inpuString.charAt(len/2+i))
                return false;
        }
        return true;
    }
    public static String truncateString(String s){
        boolean flag=true;
        while(flag&&(s.length()>0)){
        System.out.println(s);    
        flag=false;
        if((s.charAt(0)-'0')%3==0){
            s=s.substring(1);
            flag=true;
        }
        else 
            if((s.charAt(s.length()-1)-'0')%3==0){
                flag=true;
                 s=s.substring(0,s.length()-2);
            }
               
            else
                if(((s.charAt(0)-'0')+(s.charAt(s.length()-1)-96))%3==0){
                     s=s.substring(1, s.length()-2);
                    flag = true;
                }
                   
               
        
        }

        return s;
    }
    public  boolean checkStringCrossover(String a,String b,String result){
        for(int i=0;i<a.length();i++){
            if((a.charAt(i)!=result.charAt(i))&&(b.charAt(i)!=result.charAt(i)))
                return false;
        }
        return true;
    }
    public  int stringsCrossover(String[] inpuStrings, String result){
        int count=0;
        for(int i=0;i<(inpuStrings.length-1);i++){
            for(int j=i+1;j<inpuStrings.length;j++){
                 if(checkStringCrossover(inpuStrings[i], inpuStrings[j], result))
                    count++;
            }
        }
        return count;
    }
    public static void main(String[] args){
        // System.out.println(amendTheSentence("CodesignalIsAwesome"));
        // System.out.println(checkPalindrome("acbca"));
        // System.out.println(formatString("abc   a aa  a a "));
        // System.out.println(isTandemRepeat("tandemtandem"));
        //  System.out.println(truncateString("312248"));
        System.out.println(new FundamentalAlgorithms().stringsCrossover( new String[]{"abc",   "aaa",   "aba",   "bab"},"bbb"));
        
    }
}