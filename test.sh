echo "redirect_a_text_to_a_file	:zfile oi	: $(echo oi > zfile)"
echo "redirect_with_no_text:		:zfile2	""	: $(> zfile2)"
echo "double_redirect_to_a_file:	:zfile34 "" oi	: $(echo oi > zfile3 > zfile4)"

