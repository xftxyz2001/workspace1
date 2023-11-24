import java.util.Arrays;
import java.util.Scanner;

public class Main3 {

    // 给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。
    // 如果数组元素个数小于2，则返回 0。
    // 输入: [3,6,9,1]
    // 输出: 3

    // 获取输入
    private static int[] readNums() {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        scanner.close();

        // 去除首尾的中括号
        s = s.substring(1, s.length() - 1);
        if (s.isEmpty()) {
            return new int[0];
        }
        // 以逗号分隔
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

    // 已排序的数组，计算最大差值
    public static int maxDiff(int[] nums) {
        if (nums.length < 2) {
            return 0;
        }

        int max = 0;
        for (int i = 1; i < nums.length; i++) {
            int diff = nums[i] - nums[i - 1];
            if (diff > max) {
                max = diff;
            }
        }

        return max;
    }

    public static void main(String[] args) {
        // 获取输入
        int[] nums = readNums();

        // 特殊情况
        if (nums.length < 2) {
            System.out.println(0);
            return;
        }

        // 排序
        Arrays.sort(nums);

        // 计算最大差值
        int maxDiff = maxDiff(nums);
        System.out.println(maxDiff);
    }

}
