import java.util.HashMap;
import java.util.Map;

public class leetcode_377 {
    Map<Integer, Integer> map = new HashMap<>();

    public int combinationSum4(int[] nums, int target) {
        return backtrack(nums, target);
    }

    private int backtrack(int[] nums, int remains) {
        if (remains == 0)
            return 1;
        if (map.containsKey(remains)) {
            return map.get(remains);
        }
        int res = 0;

        for (int i = 0; i < nums.length; i++) {
            if (remains >= nums[i]) {
                res += backtrack(nums, remains - nums[i]);
            }
        }
        map.put(remains, res);
        return res;
    }

    public static void main(String[] args) {
        leetcode_377 leetcode_377 = new leetcode_377();
        int[] nums = {1, 2, 3};
        int target = 4;
        System.out.println("Number of combinations: " + leetcode_377.combinationSum4(nums, target));
    }
}
