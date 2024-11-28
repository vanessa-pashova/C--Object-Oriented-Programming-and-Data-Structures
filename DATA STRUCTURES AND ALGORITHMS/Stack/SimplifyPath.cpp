#include <iostream>
#include <stack>
#include <string>

std::string fromStackToString(std::stack<std::string> &stack) {
    std::string component, result;

    while(!stack.empty()) {
        component = stack.top();
        result = "/" + component + result;
        stack.pop();
    }

    return result.empty() ? "/" : result;
}

std::string simplifyPath(std::string &path) {
    std::stack<std::string> stack;
    std::string canonicalPath, component;

    if(path.front() != '/')
        throw std::invalid_argument("Invalid path given.");

    for(std::size_t i = 1; i <= path.length(); i++) {
        if(i < path.length() && path[i] != '/')
            component += path[i];

        else {
            if(component == "..") {
                if(!stack.empty())
                    stack.pop();

            }

            else if(!component.empty() && component != ".")
                stack.push(component);

            component.clear();
        }
    }

    canonicalPath = fromStackToString(stack);
    return canonicalPath;
}

int main() {
    std::string path;
    std::cin >> path;

    if(path.empty() || path.length() == 0)
        throw std::invalid_argument("Input cannot be empty.");

    std::cout << "Simplified: " << simplifyPath(path) << '\n';
}