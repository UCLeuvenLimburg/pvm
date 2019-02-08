int* `\NODE{a}{var a}` = new int`\NODE{[2]}{mem a}`;
double* `\NODE{b}{var b}` = new double`\NODE{[3]}{mem b}`;
int* `\NODE{c}{var c}` = new int`\NODE{[4]}{mem c}`;
char* `\NODE{d}{var d}` = new char`\NODE{[16]}{mem d}`;

delete[] `\NODE{b}{del b}`;
delete[] `\NODE{a}{del a}`;
delete[] `\NODE{c}{del c}`;
delete[] `\NODE{d}{del d}`;
