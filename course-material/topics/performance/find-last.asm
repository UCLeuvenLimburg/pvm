  mov  rax,qword ptr [rcx]      ; Fetch next
  test rax,rax                  ; Check for null
  je   exit                     ; Return
  nop  dword ptr [rax+rax]  

loop:
  mov  rcx,rax  
  mov  rax,qword ptr [rax]      ; Fetch next
  test rax,rax                  ; Check for null
  jne  loop                     ; Loop if not null

exit:
  mov  rax,rcx                  ; Return value
  ret 
