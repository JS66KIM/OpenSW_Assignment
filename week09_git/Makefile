# ====== 매크로 설정 ======
CC      := gcc
CFLAGS  := -Wall -Wextra -Iinclude -fPIC
SRCDIR  := src
OBJDIR  := obj
BINDIR  := bin
LIBDIR  := lib

# 연산용 소스 (6개)
OP_SRCS := $(SRCDIR)/myadd.c \
           $(SRCDIR)/mysub.c \
           $(SRCDIR)/mymul.c \
           $(SRCDIR)/mydiv.c \
           $(SRCDIR)/mymod.c \
           $(SRCDIR)/mypow.c

# obj 경로로 변환
OP_OBJS := $(OP_SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

APP_SRC := $(SRCDIR)/myapp.c
APP_OBJ := $(OBJDIR)/myapp.o
TARGET  := $(BINDIR)/myapp
SHLIB   := $(LIBDIR)/libmyops.so.1.0

# ====== 기본 목표 ======
all: $(TARGET)

# 실행파일: myapp.o + 공유 라이브러리
$(TARGET): $(APP_OBJ) $(SHLIB) | $(BINDIR)
	$(CC) -o $@ $(APP_OBJ) -L$(LIBDIR) -lmyops

# 공유 라이브러리 빌드
$(SHLIB): $(OP_OBJS) | $(LIBDIR)
	$(CC) -shared -o $@ $(OP_OBJS)
	@ln -sf libmyops.so.1.0 $(LIBDIR)/libmyops.so

# 개별 소스 -> 오브젝트
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# ====== 디렉토리 생성 ======
$(OBJDIR):
	mkdir -p $@

$(BINDIR):
	mkdir -p $@

$(LIBDIR):
	mkdir -p $@

# ====== clean ======
clean:
	rm -f $(OBJDIR)/*.o
	rm -f $(BINDIR)/myapp
	rm -f $(LIBDIR)/libmyops.so*
	@echo "clean done."
