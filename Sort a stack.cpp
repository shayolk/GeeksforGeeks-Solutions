/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
    if(s.empty()) return;
    int t=s.top();
    s.pop();
    sort();
    stack<int> tmp;
    while(!s.empty() && s.top()>t) {
        tmp.push(s.top());
        s.pop();
    }
    s.push(t);
    while(!tmp.empty()) {
        s.push(tmp.top());
        tmp.pop();
    }
}
