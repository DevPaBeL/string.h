#include <math.h>
#include <stdarg.h>

#include "s21_string.h"

typedef struct {
  char specificator;
  char flag_minus;
  char flag_plus;
  char flag_space;
  char length;
  int width;
  int precision;
} format_options;

int s21_sprintf(char *s1, const char *format, ...);
void int_form(long int x, char *buffer, int j);
double powi(int x, int y);
s21_size_t m_strlen(char *s);
int len_num(int x);
void cleanbuffer(char *s);
void float_form(double x, char *buffer, int *accur);
long int converter(s21_size_t x);
int format_parser(const char *format, format_options *options);
void copicenter(char *s1, char *s2, s21_size_t sm);
void spec_d(char *buffer, format_options *options, va_list argv);
void spec_c(char *buffer, format_options *options, char value);
void spec_f(char *buffer, format_options *options, double value);
void spec_s(char *buffer, format_options *options, char *value);
void spec_u(char *buffer, format_options *options, va_list argv);
void spec_spec(char *buffer, format_options *options);
void width_proc(char *buffer, format_options *options, int *num_sym);

int s21_sprintf(char *s1, const char *format, ...) {
  va_list argv;
  int num_sym = 0;
  va_start(argv, format);
  char buffer[1000];
  for (const char *ptr = format; *ptr != '\0'; ptr++) {
    if (*ptr == '%') {
      ptr++;
      format_options options;
      int length_option = format_parser(ptr, &options);
      ptr += length_option;
      switch (options.specificator) {
        case 'd':
          spec_d(buffer, &options, argv);
          break;
        case 'c':
          char sym = (char)va_arg(argv, int);
          spec_c(buffer, &options, sym);
          break;
        case 'f':
          double nf = va_arg(argv, double);
          spec_f(buffer, &options, nf);
          break;
        case 's':
          char *s = va_arg(argv, char *);
          spec_s(buffer, &options, s);
          break;
        case 'u':
          spec_u(buffer, &options, argv);
          break;
        case '%':
          spec_spec(buffer, &options);
          break;
      }
      char *buf = buffer;
      while (*buf) {
        s1[num_sym++] = *buf++;
      }
      cleanbuffer(buffer);
      cleanbuffer(buf);
    } else {
      s1[num_sym++] = *ptr;
    }
  }
  s1[num_sym] = '\0';
  va_end(argv);
  return num_sym;
}

void spec_d(char *buffer, format_options *options, va_list argv) {
  long long value = 0;

  if (options->length == 'l') {
    value = va_arg(argv, long);
  } else if (options->length == 'h') {
    value = (short)va_arg(argv, int);
  } else {
    value = va_arg(argv, int);
  }

  int num_sym = 0;
  char buf[1100] = {'\0'};
  if (value < 0) {
    buf[num_sym++] = '-';
  } else if (options->flag_plus == 1 && value >= 0) {
    buf[num_sym++] = '+';
  } else if (options->flag_space == 1 && value >= 0) {
    buf[num_sym++] = ' ';
  }
  char number[100];
  int sm_prec = (options->precision > len_num(value))
                    ? options->precision - len_num(value)
                    : 0;
  int_form(value, number, sm_prec);
  copicenter(buf, number, num_sym);
  num_sym = m_strlen(buf);
  if ((options->precision == -1 || options->precision == 0) && value == 0) {
    buf[0] = '\0';
    num_sym = 0;
  }
  width_proc(buf, options, &num_sym);
  copicenter(buffer, buf, 0);
}

void spec_c(char *buffer, format_options *options, char value) {
  int num_sym = 0;
  char buf[1000] = {'\0'};
  buf[num_sym++] = value;
  buf[num_sym] = '\0';
  width_proc(buf, options, &num_sym);
  copicenter(buffer, buf, 0);
}

void spec_f(char *buffer, format_options *options, double value) {
  int num_sym = 0;
  char buf[1100] = {'\0'};
  int accur = (options->precision >= 0) ? options->precision : 0;
  if (options->precision == -2) {
    accur = 6;
  }
  if (signbit(value)) {
    buf[num_sym++] = '-';
  }
  if (options->flag_plus == 1 && value >= 0) {
    buf[num_sym++] = '+';
  } else if (options->flag_space == 1 && value >= 0) {
    buf[num_sym++] = ' ';
  }

  if (options->specificator == 'f') {
    char number[100] = {'\0'};
    float_form(value, number, &accur);
    copicenter(buf, number, num_sym);
    num_sym = m_strlen(buf);
  }
  width_proc(buf, options, &num_sym);
  copicenter(buffer, buf, 0);
}

void spec_s(char *buffer, format_options *options, char *value) {
  char buf[1000] = {'\0'};
  copicenter(buf, value, 0);
  if ((s21_size_t)options->precision < m_strlen(buf)) {
    buf[options->precision] = '\0';
  }
  int num_sym = m_strlen(buf);
  width_proc(buf, options, &num_sym);
  copicenter(buffer, buf, 0);
}

void spec_u(char *buffer, format_options *options, va_list argv) {
  unsigned long long uvalue = 0;

  if (options->length == 'l') {
    uvalue = va_arg(argv, unsigned long);
  } else if (options->length == 'h') {
    uvalue = (unsigned short)va_arg(argv, unsigned int);
  } else {
    uvalue = va_arg(argv, unsigned int);
  }

  char buf[1000] = {0};
  long int value = converter(uvalue);
  int sm_prec = (options->precision > len_num(value))
                    ? options->precision - len_num(value)
                    : 0;
  int_form(value, buf, sm_prec);
  int num_sym = m_strlen(buf);
  if ((options->precision == -1 || options->precision == 0) && value == 0) {
    buf[0] = '\0';
    num_sym = 0;
  }
  width_proc(buf, options, &num_sym);
  copicenter(buffer, buf, 0);
}

void spec_spec(char *buffer, format_options *options) {
  if (options->specificator == '%') {
    buffer[0] = '%';
    buffer[1] = '\0';
  }
}

void int_form(long int x, char *buffer, int j) {
  int matr[1000] = {0};
  int num_sym = 0;
  int i = 0;
  while (num_sym != j) {
    buffer[num_sym++] = '0';
  }
  if (x < 0) {
    x = x * (-1);
  }
  while (x / 10) {
    matr[i++] = x % 10;
    x = x / 10;
  }
  matr[i] = x % 10;
  while (i >= 0) {
    buffer[j++] = '0' + matr[i--];
  }
  buffer[j] = '\0';
}

void float_form(double x, char *buffer, int *accur) {
  int num_sym = 0;
  int y = (int)x;
  x = x - y;
  x *= powi(10, (*accur));
  char s1[100], s2[100];
  int checkminus = 0;
  if (signbit(x)) {
    x *= -1;
    checkminus = 1;
  }
  int z = (int)(x + 0.5);
  int ln = len_num(z);
  if (ln > (*accur) && (*accur) > 0) {
    y = (checkminus == 0) ? (y + 1) : (y - 1);
    z = 0;
    ln = 1;
  }
  int_form(y, s1, 0);
  for (int i = 0; s1[i] != '\0'; i++) {
    buffer[num_sym++] = s1[i];
  }
  if ((*accur) > 0) {
    int_form(z, s2, (*accur) - ln);
    buffer[num_sym++] = '.';
    for (int i = 0; s2[i] != '\0'; i++) {
      buffer[num_sym++] = s2[i];
    }
    buffer[num_sym] = '\0';
  }
}

double powi(int x, int y) {
  double result = 1.0;
  for (int i = 0; i < y; i++) {
    result *= x;
  }
  return result;
}

s21_size_t m_strlen(char *s) {
  s21_size_t len = 0;
  for (; *(s + len); len++);
  return len;
}

int len_num(int x) {
  int size = 0;
  if (x != 0) {
    while (x != 0) {
      size++;
      x /= 10;
    }
  } else {
    size = 1;
  }
  return size;
}

void cleanbuffer(char *s) {
  int l = m_strlen(s);
  for (int i = 0; i < l; i++) {
    s[i] = '\0';
  }
}

long int converter(s21_size_t x) {
  long int y = 0;
  int st = 0;
  while (x % 10) {
    y += (x % 10) * (int)powi(10, st);
    st++;
    x /= 10;
  }
  return y;
}

void copicenter(char *s1, char *s2, s21_size_t sm) {
  s21_size_t len = m_strlen(s2);
  for (s21_size_t i = 0; i < len; i++) {
    s1[i + sm] = s2[i];
  }
  s1[len + sm] = '\0';
}

void width_proc(char *buffer, format_options *options, int *num_sym) {
  int ost_width = options->width - *(num_sym);
  if (options->width && ost_width > 0 && options->flag_minus == 0) {
    for (int i = (*num_sym) - 1; i >= 0; i--) {
      buffer[i + ost_width] = buffer[i];
    }
    for (int i = 0; i < ost_width; i++) {
      buffer[i] = ' ';
    }
    *(num_sym) += ost_width;
  } else if (options->width && ost_width > 0 && options->flag_minus == 1) {
    for (int i = (*num_sym); i < options->width; i++) {
      buffer[i] = ' ';
    }
  }
}

int format_parser(const char *format, format_options *options) {
  const char *ptr = format;

  options->specificator = '\0';
  options->flag_minus = 0;
  options->flag_plus = 0;
  options->flag_space = 0;
  options->width = 0;
  options->precision = -2;
  options->length = '\0';

  while (*ptr == '-' || *ptr == '+' || *ptr == ' ') {
    if (*ptr == '-') options->flag_minus = 1;
    if (*ptr == '+') options->flag_plus = 1;
    if (*ptr == ' ') options->flag_space = 1;
    ptr++;
  }
  if (*ptr >= '0' && *ptr <= '9') {
    options->width = *ptr - '0';
    ptr++;
    while (*ptr >= '0' && *ptr <= '9') {
      options->width *= 10;
      options->width += *ptr - '0';
      ptr++;
    }
  }
  if (*ptr == '.') {
    ptr++;
    options->precision = -1;
    if (*ptr >= '0' && *ptr <= '9') {
      options->precision = *ptr - '0';
      ptr++;
      while (*ptr >= '0' && *ptr <= '9') {
        options->precision *= 10;
        options->precision += *ptr - '0';
        ptr++;
      }
    }
  }
  if (*ptr == 'l' || *ptr == 'h') {
    options->length = *ptr;
    ptr++;
  }

  if (*ptr == 'd' || *ptr == 'c' || *ptr == 'f' || *ptr == 's' || *ptr == 'u' ||
      *ptr == '%') {
    options->specificator = *ptr;
  }

  return ptr - format;
}
