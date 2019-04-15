#include <iostream>
#include <cmath>// 这是c++中使用的数学公式，需要导入的头文件
#include <cstring>
#include <vector>
#include <string>

using namespace std;

//声明变量
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 第一题
int sumNumbers(int nums[], int target) {

    for (int i = 0; i < 6; ++i) {
        int a = nums[i];
        int b = target - a;

        for (int j = 0; j < 6; ++j) {
            if (j == i) { break; }
            if (nums[j] == b) {
                return nums[j];
            }
        }
    }
    return 0;
}
// 第二题：给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ret = new ListNode(0);
        ListNode *n   = ret;
        ListNode *n1  = l1;
        ListNode *n2  = l2;

        while (n1 || n2) {

            int v = n->val;
            if (n1) {
                v += n1->val;
                n1 = n1->next;
            }
            if (n2) {
                v += n2->val;
                n2 = n2->next;
            }

            n->val = v%10;

            int val = v/10;
            if (v >= 10 || n1 || n2) {
                ListNode *t = new ListNode(val);
                n->next = t;
                n = n->next;
            }
        }

        return ret;
    }
};
// 第三题：给定一个字符串，找出其中不含有重复字符的最长子串的长度
int lengthOfLongestSubstring(string s) {
    if (s == "") { return 0; }

    string time = "";
    int len = 0;
    for (int i = 0; i < s.length(); ++i) {
        int key = time.find(s[i]);
        if (key != time.npos) {
            time.assign(time, key+1, time.length()-key);
        }
        time+=s[i];
        len = time.length() > len ? time.length() : len;
    }
    return len;
}
// 第四题：给定两个大小为m和n的有序数组，找出这两个有序数组的中位数，并且求出算法的时间复杂度O(log(m+n))，假设m和n不会同时为空
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    return 0;
}
// 第五题：最长回文子串
/*  暴力破解的时间复杂度是n^3，主要考虑如何去降低时间复杂度的同时去.
    我的思路:动态规划
    时间复杂度为O(n)
 */
string longestPalindrome(string s) {

    const int n = s.size();
    bool dp[n][n];
    memset(dp, 0, sizeof(dp));

    int maxlen = 1; // 保持最长回文子串长度
    int start = 0;  // 保存最长回文子串起点
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (i - j < 2)
            {
                dp[j][i] = (s[i] == s[j]);
            }
            else
            {
                dp[j][i] = (s[i] == s[j] && dp[j + 1][i - 1]);
            }
            
            if (dp[j][i] && maxlen < i - j + 1)
            {
                maxlen = i - j + 1;
                start = j;
            }
        }
    }
    return s.substr(start, maxlen);
}
// 马拉车算法，时间复杂度为O(n)--第五题
/* 马拉车算法详细说明：
        由于回文串的长度可奇可偶，比如“bob”是奇数形式的回文，“noon”是偶数形式的回文，马拉车算法的第一步是预处理，做法是在每一个字符的左右加上一个特殊字符，比如加上‘#’，那么
        bob     --->    #b#o#b#
        noon    --->    #n#o#o#n#
        这样做的好处是不论原字符串是奇数还是偶数个，处理后得到的字符串的个数都是奇数个，这样就不用分情况讨论了，而可以一起处理。接下来我们还需要处理字符串t等长的数组p，其中p[i]表示以t[i]字符为中心的回文子串的半径，若p[i]=1,则该回文子串就是t[i]本身。
        * 最长子串的长度是半径减1，起始位置是中间位置减去半径再除以2.
        那么下面我们来看如何求p数组，需要新增两个辅助变量mx和id，其中id为能延伸到最右端的位置的那个回文子串的中心点位置，mx是回文能延伸到最右端的位置，这样个算法最核心的一行如下：
            p[i] = mx ? min(p[2*id-i], mx-i) : 1;
    */
string Manacher(string s) {
    string t = "#";
    for (int i = 0; i < s.size(); i++)
    {
        t += s[i];
        t += "#";
    }
    
    vector<int> p(t.size(), 0);
    int mx = 0, id = 0, resLen = 0, resCenter = 0; // resLen 回文子串的长度  resCenter回文子串的中心位置
    for (int i = 0; i < t.size(); i++)
    {
        p[i] = mx > i ? min(p[2*id-1], mx-i) : 1;
        while (t[i + p[i]] == t[i - p[i]])
        {
            ++p[i];
        }
        
        if (mx < i + p[i])
        {
            mx = i + p[i];
            id = i;
        }

        if (resLen < p[i])
        {
            resLen = p[i];
            resCenter = i;
        }
    }
    
    return s.substr((resCenter - resLen)/2, resLen - 1);
}
// 第六题：Z字形变换
string convert(string s, int numRows) {
    if (numRows == 1) return s;

    vector<string> rows(min(numRows, int(s.size())));
    int curRow = 0;
    bool goingDown = false;

    for (char c : s) {
        rows[curRow] += c;
        if (curRow == 0 || curRow == numRows - 1)
        {
            goingDown = !goingDown;
            curRow += goingDown ? 1 : -1;
        }
        string ret;
        for (string row : rows) ret += row;
        return ret;
        
    }
    
}
// 第七题：整数反转
int reverse(int x) {
    int rev = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        if (rev > INT_MAX/10 || (rev == INT_MAX/10 && pop > 7)) return 0;
        if (rev < INT_MIN/10 || (rev == INT_MIN/10 && pop < -8)) return 0;
        rev = rev * 10 + pop;
    }
    return rev;
}
// 第八题：字符串转换整数（atoi）
string myAtoi(string str) {
    if (str.length() == 0) return 0;
    string s;
    for (int i = 0; i < str.length(); ++i) {
        if (str.at(i) == '-'
        || str.at(i) == '0'
        || str.at(i) == '1'
        || str.at(i) == '2'
        || str.at(i) == '3'
        || str.at(i) == '4'
        || str.at(i) == '5'
        || str.at(i) == '6'
        || str.at(i) == '7'
        || str.at(i) == '8'
        || str.at(i) == '9') {
            s += str.at(i);
        } else {
            if (str.at(i) != ' ') break;//空格跳过
        }
    }

    return s;
}
// 第九题：回文数
bool isPalindrome(int x) {
    if (x < 0) return false;
    else {
        int sum = 0;
        int val = x;
        while (x) {
            if (sum > INT_MAX/10) return false;
            sum *= 10;
            if (sum >INT_MIN - x%10) return false;
            sum += x%10;
            x/=10;
        }
        if (sum == val) return true;
    }
    return false;
}
// 第十题：正则表达式匹配   s是字符串，   p是字符模式，实现支持‘.’和‘*’的正则表达式匹配
bool isMatch(string s, string p) {
    
}
int main() {
    cout << "LeetCode算法刷题练习" << endl;
    int numbers[9] = {2,3,4,5,6,7,1,2,5};
    // cout << "输出结果1：" << longestPalindrome("abcdc2ba") << endl; // 时间复杂度为O(n^2)
    // cout << "输出结果2：" << Manacher("abcdcba") << endl;// 马拉车算法，时间复杂度为O(n)
    string s = "12qweads";

    cout << "输出结果" << isMatch("dd*2do.","*") << endl;

    return 0;
}

