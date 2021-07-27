cint main(void)
{
	char * k=hangman("1234567890 |\!\"£$ % &/ () = ? ^ ' abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ <>;:_,.-[]{}@#","aeiou");
	free(k);

	return 0;

}