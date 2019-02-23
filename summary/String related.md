### String related

### 分割字符串方法

``` C++
string simplifyPath(string path) {
  string res, t;
  stringstream ss(path);
  vector<string> v;
  
  while(getline(ss, t, '/')) {
    if(t == "" || t == ".") continue;
    if(t == ".." && !v.empty()) v.pop_back();
    else if(t != "..") v.push_back(t);
  }
  
  for(string s : v) res += "/" + s;
  return res.empty() ? "/":res;
}

```

``` C++
string simplifyPath(string path) {

  vector<string> v;
  int i = 0;
  
  while(i < path.size()) {
    while(i < path.size() && path[i++] == '/');
    if( i == path.size()) break;
    
    int start = i;
    
    while(i < path.size() && path[i++] == '/');
    int end = i-1;
    
    string s = path.substr(start, end - start + 1)；
    if( s == ".." && !v.empty()) {
      v.pop_back();
    } else if(s != ".") {
      v.push_back(s);
    }
  }
  for(string s : v) res += "/" + s;
  return res.empty() ? "/":res;
  
}
```

