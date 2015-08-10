import java.util.Stack;

public class BSTIterator {
    Stack<TreeNode> stk;
    public BSTIterator(TreeNode root) {
        stk=new Stack<TreeNode>();
        while(root!=null){
            stk.push(root);
            root=root.left;
        }
    }

    /** @return whether we have a next smallest number */
    public boolean hasNext() {
        return !stk.isEmpty();
    }

    /** @return the next smallest number */
    public int next() {
        if(!hasNext())
            return Integer.MIN_VALUE;
        TreeNode top=stk.pop();
        int res=top.val;
        top=top.right;
        while(top!=null){
            stk.push(top);
            top=top.left;
        }
        return res;
    }
}

public class InOrderBinaryTreeIterator {
    Stack<TreeNode> stack = new Stack<TreeNode>();
    TreeNode current;

    /** Push node cur and all of its left children into stack */
    private void pushLeftChildren(TreeNode cur) {
        while (cur != null) {
            stack.push(cur);
            cur = cur.left;
        }
    }

    public InOrderBinaryTreeIterator(TreeNode root) {
        pushLeftChildren(root);
    }

    public boolean hasNext() {
        return !stack.isEmpty();
    }

    public void next() {
        if (!hasNext()) {
            throw new NoSuchElementException("All nodes have been visited!");
        }

        TreeNode res = stack.pop();
        current = res;
        pushLeftChildren(res.right);

    }
}
