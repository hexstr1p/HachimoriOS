void printf(char* str) {
  unsigned short* VideoMemory = (unsigned short*)0xb8000;
  for (int i= 0; str[i] != '\0'; ++i) {
    VideoMemory[i] = (VideoMemory[i] & 0xFF00) | str[i];
  }
}

typedef void (*constructor)();
extern "C" constructor start_ctors;
extern "C" constructor end_ctors;

extern "C" void CallConstructors() {
  for (constructor* iter = &start_ctors; *iter != end_ctors; ++iter) {
    (*iter)();
  }
}

extern "C" void KernelMain(void* multiboot_structure, unsigned int magic_number) {
  printf("Systems Ready!");
  while(true);
}
