import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;

public class Main {

    // 编写一段程序，前序遍历二叉树

    // 定义二叉树节点
    public static class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode(int x) {
            val = x;
        }
    }

    // 给定层次遍历数组（空节点用null表示），构建二叉树
    public static TreeNode buildTree(Integer[] nums) {
        // 如果数组为空或长度为0，返回null
        if (nums == null || nums.length == 0) {
            // || nums.length == 1 && nums[0] == null
            return null;
        }

        // 创建一个队列来存储节点
        Queue<TreeNode> queue = new LinkedList<>();
        // 创建根节点
        TreeNode root = new TreeNode(nums[0]);
        // 将根节点添加到队列中
        queue.offer(root);
        int i = 1;

        // 当队列不为空时，继续执行
        while (!queue.isEmpty()) {
            // 从队列中取出一个节点
            TreeNode currentNode = queue.poll();

            // 如果数组中没有更多元素，就结束循环
            if (i >= nums.length) {
                break;
            }

            // 如果当前元素不为null，创建一个新的左子节点
            if (nums[i] != null) {
                TreeNode leftNode = new TreeNode(nums[i]);
                // 将新的左子节点添加到当前节点
                currentNode.left = leftNode;
                // 将新的左子节点添加到队列中
                queue.offer(leftNode);
            }
            i++;

            // 如果数组中没有更多元素，就结束循环
            if (i >= nums.length) {
                break;
            }

            // 如果当前元素不为null，创建一个新的右子节点
            if (nums[i] != null) {
                TreeNode rightNode = new TreeNode(nums[i]);
                // 将新的右子节点添加到当前节点
                currentNode.right = rightNode;
                // 将新的右子节点添加到队列中
                queue.offer(rightNode);
            }
            i++;
        }

        // 返回根节点
        return root;
    }

    // 返回遍历结果数组（递归）
    private static List<Integer> list;

    public static List<Integer> preOrder(TreeNode root) {
        list = new ArrayList<>();
        preOrderRec(root);

        return list;
    }

    private static void preOrderRec(TreeNode node) {
        if (node == null) {
            return;
        }
        list.add(node.val);
        preOrderRec(node.left);
        preOrderRec(node.right);
    }

    // 获取输入
    private static Integer[] readNums() {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.nextLine();
        scanner.close();

        // 去除首尾的中括号
        s = s.substring(1, s.length() - 1);

        // 只有中括号，返回空数组
        // Exception in thread "main" java.lang.NullPointerException: Cannot invoke
        // "java.lang.Integer.intValue()" because "nums[0]" is null
        if (s.isEmpty()) {
            return new Integer[0];
        }
        // 以逗号分隔
        String[] strings = s.split(",");
        // 转换为整数数组
        Integer[] nums = new Integer[strings.length];
        for (int i = 0; i < strings.length; i++) {
            try {
                nums[i] = Integer.parseInt(strings[i]);
            } catch (NumberFormatException e) {
                nums[i] = null;
            }
        }

        return nums;
    }

    // 编写一段程序，前序遍历二叉树
    public static void main(String[] args) {
        // 获取输入
        Integer[] strings = readNums();

        // 构建二叉树
        TreeNode root = buildTree(strings);

        // 前序遍历
        List<Integer> list = preOrder(root);
        System.out.println(list);

    }
}