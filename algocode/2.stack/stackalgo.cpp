//��Ŀ��Ҫ��Դ��leetcode

/*�沨�����ʽ����
���� �沨����ʾ��������ʽ��ֵ��
��Ч��������� +��-��*��/ ��ÿ��������������������Ҳ��������һ���沨�����ʽ��  */


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



/*������
����һ���ַ������ʽ s ������ʵ��һ�����������������㲢��������ֵ��
���������������������֡�  */


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



/*�ַ�������
����һ������������ַ������������������ַ�����
�������Ϊ: k[encoded_string]����ʾ���з������ڲ���encoded_string�����ظ�k�Ρ�ע��k��֤Ϊ��������
�������Ϊ�����ַ���������Ч�ģ������ַ�����û�ж���Ŀո�������ķ��������Ƿ��ϸ�ʽҪ��ġ�
���⣬�������Ϊԭʼ���ݲ��������֣����е�����ֻ��ʾ�ظ��Ĵ���k�����粻�������3a��2[4]�����롣  */


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
