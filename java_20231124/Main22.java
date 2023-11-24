import java.util.Scanner;

public class Main22 {
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
    public static int removeDuplicate(int[] array) {
        if (array == null || array.length == 0) {
            return 0;
        }

        int n = array.length;
        int count = 0;

        for (int i = 0; i < n; i++) {
            int index = Math.abs(array[i]) % n; // 获取当前数字应该存放的位置

            if (array[index] >= 0) {
                array[index] = -array[index]; // 标记该位置数字出现过
                count++;
            }
        }

        // 还原数组
        for (int i = 0; i < n; i++) {
            if (array[i] < 0) {
                array[i] = -array[i];
            }
        }

        return count;
    }

    // 格式化输出
    public static void printArray(int[] array, int length) {
        System.out.print(length + ",nums=[");
        for (int i = 0; i < length; i++) {
            System.out.print(array[i]);
            if (i != length - 1) {
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
        int length = removeDuplicate(array);
        // 输出
        printArray(array, length);
    }
}
