int maxDepth(TreeNode *now)
{
	int dep1 = 0,dep2 = 0; //dep1左子树深度，dep2右子树深度
	if (now->left != NULL) dep1 = maxDepth(now->left);
	if (now->right != NULL) dep2 = maxDepth(now->right);
	int dep = dep1 > dep2 ? dep1 : dep2;
	return dep+1;
}
