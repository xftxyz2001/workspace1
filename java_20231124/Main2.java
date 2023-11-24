import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main2 {

    // 有一个长度为n的数组array里面所有数字都在0~n-1范围内。
    // 请写一个函数/方法，清除数组中的重复数字。
    // 输入: 1,1,2
    // 输出: 2,nums=[1, 2]

    // 获取输入
    private static int[] readNums() {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        scanner.close();

        // 逗号分隔
        String[] strings = s.split(",");
        // 转换为整数数组
        int[] nums = new int[strings.length];
        for (int i = 0; i < strings.length; i++) {
            try {
                nums[i] = Integer.parseInt(strings[i]);
            } catch (NumberFormatException e) {
                nums[i] = 0;
            }
        }
        return nums;
    }

    // 去重
    public static int[] removeDuplicate(int[] array) {
        Set<Integer> set = new HashSet<>();
        for (int num : array) {
            set.add(num);
        }
        int[] result = new int[set.size()];
        int i = 0;
        for (int num : set) {
            result[i++] = num;
        }
        return result;
    }

    // 格式化输出
    public static void printArray(int[] array) {
        System.out.print(array.length + ",nums=[");
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i]);
            if (i != array.length - 1) {
                System.out.print(", ");
            }
        }
        System.out.println("]");
    }

    // 主函数
    public static void main(String[] args) {
        // 获取输入
        int[] array = readNums();
        // 去重
        int[] result = removeDuplicate(array);
        // 输出
        printArray(result);
    }
}
