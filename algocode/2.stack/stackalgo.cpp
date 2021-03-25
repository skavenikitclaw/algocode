//题目主要来源于leetcode

/*逆波兰表达式计算
根据 逆波兰表示法，求表达式的值。
有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。  */


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num_stack;
        for(auto &c: tokens){
            if(isdigit(c.at(0)) || (c.at(0) == '-' && c.length() > 1) ){
                num_stack.push(std::stoi(c, nullptr, 10));
            }else{
                int num2 = num_stack.top();
                num_stack.pop();
                int num1 = num_stack.top();
                num_stack.pop();
                switch (c.at(0)){
                    case '+': num_stack.push(num1 + num2);
                        break;
                    case '-': num_stack.push(num1 - num2);
                        break;
                    case '*': num_stack.push(num1 * num2);
                        break;
                    case '/': num_stack.push(num1 / num2);
                        break;
                }
            }
        }
        return num_stack.top();
    }
};



/*计算器
给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
整数除法仅保留整数部分。  */


class Solution {
public:
    int calculate(string s) {
        vector<int> ret;
        char persign = '+';
        int num = 0;
        int len=s.length();
        int i;

        for(i=0;i<len;i++)
        {
            if(isdigit(s[i]))
            {
                num=num*10+(s[i]-'0');
            }
            if(!isdigit(s[i])&&s[i]!=' '||i==len-1)
            {
                switch(persign)
                {
                    case '+':
                        ret.push_back(num);
                        break;
                    case '-':
                        ret.push_back(-num);
                        break;
                    case '*':
                        ret.back() *= num;
                        break;
                    case '/':
                        ret.back() /= num;
                        break;
                }
                num = 0;
                persign = s[i];
            }
        }
        return accumulate(ret.begin(),ret.end(),0);
    }
};



/*字符串解码
给定一个经过编码的字符串，返回它解码后的字符串。
编码规则为: k[encoded_string]，表示其中方括号内部的encoded_string正好重复k次。注意k保证为正整数。
你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数k，例如不会出现像3a或2[4]的输入。  */


class Solution {
public:
    string decodeString(string s) {
        if (s.empty())
            return "";
        stack<pair<string, int>> mstack;
        string res= "";
        string temp;
        int multi= 0;
        pair<string, int> top_pair;
        for (int i= 0; i< s.length(); i++)
        {
            if (s[i]>= '0' && s[i]<= '9')
                multi = multi*10+ (s[i]- '0');
            else if (s[i]== '[')
            {
                mstack.push(make_pair(res, multi));
                res= "";
                multi = 0;
            }
            else if (s[i]== ']')
            {
                top_pair= mstack.top();
                mstack.pop();
                temp = res;
                for (int j= 0; j< top_pair.second-1; j++)
                    res+= temp;
                res= top_pair.first+ res;
            }
            else
                res+= s[i];
        }
        return res;
    }
};
