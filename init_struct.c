#include <stdio.h>

void lame_hexdump_one_line(const void* pv, size_t len) {
  if (len < 8) { // TODO
    printf("TODO: implement dump of part line\n");
  } else {
    const char* p = (const char*)pv;
    printf("%02x %02x %02x %02x %02x %02x %02x %02x\n",
        p[0], p[1], p[2], p[3], p[4], p[5], p[6], p[7]);
  }
}

void lame_hexdump(const void* p, size_t len) {
  const void* END_PTR = p + len;
  size_t num_lines = len / 8;  // let's print 8 bytes a line ... do'oh!
  // TODO: %zu may be platform specific??
  fprintf(stderr, "Write %zu lines, and %zu bytes\n", num_lines, len);
  for (size_t lineno = 0; lineno < num_lines || p < END_PTR; ++lineno, p += 8) {
    lame_hexdump_one_line(p, 8);
    fprintf(stderr, "line: %zu,  ptr: %p,  end: %p\n", lineno, p, END_PTR);
  }
  // TODO: last line?
}

struct heystruct {
  char buf[64]; // just some byte array
};

struct heystruct table[10];  // we have an array of 10 heystruct entries;

int main(int argc, const char ** argv) {
  lame_hexdump(&table[0], sizeof(struct heystruct));
  // lame_hexdump(table, sizeof(table));
  return 0;
}
