`\pgfmark{example 1 line 1 start}`int x = 5;`\pgfmark{example 1 line 1 end}`
`\pgfmark{example 1 line 2 start}`int* p = &x;`\pgfmark{example 1 line 2 end}`

`\pgfmark{example 1 line 3 start}`x++;`\pgfmark{example 1 line 3 end}`

`\pgfmark{example 1 line 4 start}`std::cout << `\pgfmark{example 1 dereference start}`*p`\pgfmark{example 1 dereference end}` << std::endl;`\pgfmark{example 1 line 4 end}`
