enum class E : int { A = 7 };

int main()
{
	// 5.2.8/9
	(void)static_cast<int>(E::A);
}
