#include <iostream>
#include <string>
#include "Value.h"
#include "Nodes.h"
int n;
Value *v[100001];
std::string s;
int main()
{
    std::cin >> n;
    int a, b;
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> s;
        if(s == "Constant")
        {
            std::cin >> a;
            v[i] = new Constant(a);
        }
        else if(s == "Plus")
        {
            std::cin >> a >> b;
            v[i] = new Plus(v[a], v[b]);
        }
        else if(s == "Sub")
        {
            std::cin >> a >> b;
            v[i] = new Sub(v[a], v[b]);
        }
        else if(s == "Multiply")
        {
            std::cin >> a >> b;
            v[i] = new Multiply(v[a], v[b]);
        }
        else if(s == "Print")
        {
            std::cin >> a;
            v[i] = new Print(v[a]);
            std::cout << v[i]->calc() << std::endl;
        }
        else if(s == "Modify")
        {
            std::cin >> a >> b;
            // 向下转换
            Constant* pc = dynamic_cast<Constant*>(v[a]);
            pc->set_value(b);
            v[i] = new Print(v[a]);
        }
    }

    // 删掉每一个节点
    for(int i = 1; i <= n; ++i) {
        delete v[i];
    }
	return 0;
}
