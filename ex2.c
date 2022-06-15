int main()
{
	while (1)
	{
		float centimeters;
		printf("Enter a height in centimeters (<=0 to quit): ");

		if (scanf("%f", &centimeters))
		{
			if (centimeters > 0)
			{
				float totalInches = centimeters / 2.54F;
				int feet = totalInches / 12;
				int a = feet * 12;
				float inches = totalInches - a;

				printf("%.1f cm = %d feet, %.1f inches\n", centimeters, feet, inches);
			}
			else if (centimeters == 0)
			{
				printf("Quitting!\n");
				break;
			}
			else
			{
				printf("Not a valid measurement in centimeters.\n");
				break;
			}
		}
		else
		{
			printf("Not a valid measurement in centimeters.\n");
			break;
		}
	}

	return 0;
}
