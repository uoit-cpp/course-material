float average3(float a, float b, float c)
{
	return (a+b+c)/3.0;
} 

void average(const float* arr, int n, float& ave, float& sd)
{
	int i;
	float sum = 0;
	for (i = 0; i < n; ++i) {
		sum += arr[i];
	}
	ave = sum / static_cast<float>(n);
	sd = 0.0;
}
