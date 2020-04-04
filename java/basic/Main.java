import java.util.Scanner;

/*
 * 回文数
 * */

public class Main {
    public static void main(String[] args) {
        System.out.println("请输入测试组数目T：");
        Scanner scanner=new Scanner(System.in);
        int T=scanner.nextInt(),n,temp,digit,digit_count[]=new int[]{0,9,9,90,90,900,900,9000,9000,90000,90000,900000},high_low,middle,j,remainder,hemi_digit=0,floorhemi_digit=0;
        String result,hemi_str,invert_str;

        for(int i=0;i<T;i++) {
            n = scanner.nextInt();
            temp=n;
            digit=1;
            //判断第n个回文数至少有几位
            while (temp>digit_count[digit]){
                temp-=digit_count[digit];
                digit++;
            }
            //System.out.println("temp"+temp);
            //System.out.println("digit"+digit);
            if(digit%2==0) {
                hemi_digit=digit/2;
                floorhemi_digit=hemi_digit;
            }else {
                hemi_digit=(digit+1)/2;
                floorhemi_digit=hemi_digit-1;
            }

            //System.out.println("hemi_digit"+hemi_digit);
            //确认每一位数
            high_low=(int)(temp/Math.pow(10,hemi_digit-1))+1;//最高位和最低位
            middle=(int)(temp%Math.pow(10,hemi_digit-1))-1;//中间位
            hemi_str=Integer.toString(high_low*(int)Math.pow(10,hemi_digit-1)+middle);
            invert_str="";
            for(j=0;j<floorhemi_digit;j++)invert_str=hemi_str.charAt(j)+invert_str;
            //System.out.println("hemi_str " + hemi_str);
            //System.out.println("invert_str " + invert_str);
            result=hemi_str+invert_str;
            System.out.println(result);
        }
    }
}