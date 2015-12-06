/*
 * 作者：何伟伟
 * 作者邮箱：<1830973318@qq.com>
 * 文件名: quickSort.cpp
 * 创建日期: 2015年01月09日 星期五 07时12分10秒
 * 程序想法：今天的感觉，做什么事情兴趣是第一位的！
 * 我现在在想，与女孩子相处有趣是第一位的，你如何把对话，交流变得有趣，这才是最重要的！不然我也不会花时间与任何女孩子交流！
 */
// b）寻找中间数，分别对左边和右边的数据进行排序
void _quick_sort(int array[], int start, int end)
{
	int middle;
	if(start >= end)
		return;

	middle = get_middle(array, start, end);
	_quick_sort(array, start, middle -1);
	_quick_sort(array, middle + 1, end);
}

//数组指针不为空，数组长度不为零！
void quick_sort(int array[], int length)
{
	int median = 0;
	if(NULL == array || 0 == length)
		return;

	_quick_sort(array, 0, length-1);
}
