.PHONY: clean, fclean
CC=/usr/bin/gcc
CFLAGS=-Wall -Wextra -Werror
LPATH=./lib/
OPATH=./obj/
FPATH=./src/
FILES=main.c standart.c brainfuck.c
OBJECTS=$(FILES:.c=.o)
EXECUTABLE=brainfuck

define skull
DONE

	              :::!~!!!!!:.
	          .xUHWH!! !!?M88WHX:.
	        .X*#M@$$!!  !X!M$$$$$$$$$$$$WWx:.
	       :!!!!!!?H! :!$$!$$$$$$$$$$$$$$$$$$$$8X:
	      !!~  ~:~!! :~!$$!#$$$$$$$$$$$$$$$$$$$$8X:
	     :!~::!H!<   ~.U$$X!?R$$$$$$$$$$$$$$$$MM!
	     ~!~!!!!~~ .:XW$$$$$$U!!?$$$$$$$$$$$$RMM!
	       !:~~~ .:!M"T#$$$$$$$$WX??#MRRMMM!
	       ~?WuxiW*`   `"#$$$$$$$$8!!!!??!!!
	     :X- M$$$$$$$$       `"T#$$T~!8$$WUXU~
	    :%`  ~#$$$$$$m:        ~!~ ?$$$$$$$$$$$$
	  :!`.-   ~T$$$$$$$$8xx.  .xWW- ~""##*"
.....   -~~:<` !    ~?T#$$$$@@W@*?$$$$      /`
W$$@@M!!! .!~~ !!     .:XUW$$W!~ `"~:    :
"~~`.:x%`!!  !H:   !WM$$$$$$$$Ti.: .!WUn+!`
:::~:!!`:X~ .: ?H.!u "$$$$$$B$$$$$$!W:U!T$$$$M~
.~~   :X@!.-~   ?@WTWo("*$$$$$$W$$TH$$! `
Wi.~!X$$?!-~    : ?$$$$$$B$$Wu("**$$RM!
$$R@i.~~ !     :   ~$$$$$$$$$$B$$$$en:``
?MXT@Wx.~    :     ~"##*$$$$$$$$M~'
endef
export skull

all: $(EXECUTABLE)

$(EXECUTABLE): $(addprefix $(OPATH), $(OBJECTS))
	@$(CC) -I $(LPATH) $(addprefix $(OPATH), $(OBJECTS)) -o $@
	@echo "Made the executable"
	@echo "$$skull"

$(addprefix $(OPATH), %.o): $(addprefix $(FPATH), %.c)
	@$(CC) -I $(LPATH) -c -o $@ $<
	@echo "Made the objective file for $<"
	
re: fclean all

clean:
	@rm -f $(OPATH)*.o
	@echo "Deleted the objective files"

fclean: clean
	@rm -f $(EXECUTABLE)
	@echo "Deleted the executable"
