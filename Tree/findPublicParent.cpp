void findPublicParent()
	{
		int i(0), j(0);
		cin >> i >> j;

		while (i != j)
		{
			i > j ? i >>= 1 : j >>= 1;
		}
		cout << i << endl;
	}
