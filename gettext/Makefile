TARGET:=gettext
%.po:%.c
	xgettext -a $^ -o $@  --from-code=utf-8
	sed -i s/charset=CHARSET/charset=UTF-8/g gettext.po
	editor gettext.po

%.mo:%.po locatle
	msgfmt $< -o $@
	cp $@ locale/zh_CN/LC_MESSAGES/

locatle:
	mkdir -p locale/zh_CN/LC_MESSAGES/

%:%.c
	gcc -o $@ $<

clean:
	rm -fr locale *.mo *.po gettext
