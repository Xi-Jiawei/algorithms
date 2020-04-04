import com.sun.jna.Library;
import com.sun.jna.Native;

public class DllTest {
    public interface CLibrary extends Library {
        //相对路径相对于C:\Windows\System32或当前路径，所以建议使用绝对路径
        CLibrary INSTANCE = (CLibrary)Native.load("D:\\Users\\veev\\Java\\IdeaProjects\\Test\\src\\dll\\DllForJava", CLibrary.class);
        int maximum(int a, int b);
    }

    public static void main(String[] args) {
        int result=CLibrary.INSTANCE.maximum(3,5);
        System.out.println(result);
    }
}
