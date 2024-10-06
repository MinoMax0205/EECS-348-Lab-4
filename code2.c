#include <stdio.h>

//Function prototypes to call necesarry methods to convert
float CelsiusToKelvin(float c);
float KelvinToCelsius(float k);
float CelsiusToFarenheit(float c);
float FahrenheitToCelsius(float f);
float FahrenheitToKelvin(float f);
float KelvinToFahrenheit(float k);

//Functions responsible for converting
float CelsiusToKelvin(float c) {
	return c + 273.15; }

float KelvinToCelsius(float k) {
	return k - 273.15; }

float CelsiusToFarenheit(float c) {
	return (c * 9.0 / 5.0) + 32.0; }

float FahrenheitToCelsius(float f) {
	return (f - 32.0) * 5.0/9.0; }

float FahrenheitToKelvin(float f) {
	return CelsiusToKelvin(FahrenheitToCelsius(f)); }

float KelvinToFahrenheit(float k) {
	return CelsiusToFarenheit(KelvinToCelsius(k)); }

int main() {

	//These three are the inputs from the user
	float temp;
	int scale;
	int conversion;

	//Variables for output
	float ConvertedTemp;
	float WeatherCheck;
	
	//Lines to get input from user
	printf("Enter a temperature: ");
	scanf("%f", &temp);
	printf("Choose the scale for the temperature: 1) Fahrenheit 2) Celsius 3) Kelvin: ");
	scanf("%d", &scale);
	printf("Choose the conversion target: 1) Fahrenheit 2) Celsius 3) Kelvin): ");
	scanf("%d", &conversion);
	
	//Fahrenheit Conversions
	if (scale == 1) {
		if (conversion == 2) {
			ConvertedTemp = FahrenheitToCelsius(temp); }
		else if (conversion == 3) {
			ConvertedTemp = FahrenheitToKelvin(temp); }
		else {
			ConvertedTemp = temp; }
	}
	
	//Celsius Conversions
	else if (scale == 2) {
		if (conversion == 1) {
			ConvertedTemp = CelsiusToFarenheit(temp);
			 }
		else if (conversion == 3) {
			ConvertedTemp = CelsiusToKelvin(temp); }
		else {
			ConvertedTemp = temp; }
	}
	
	//Kelvin Conversions
	else if (scale == 3) {
		if (conversion == 1) {
			ConvertedTemp = KelvinToFahrenheit(temp); }
		else if (conversion == 2) {
			ConvertedTemp = KelvinToCelsius(temp); }
		else {
			ConvertedTemp = temp; }
	}

	else {
		printf("Invalid input entered. \n");
		return 1;}	
	
	//Responsible for checking weather temp for output message
	if (scale == 1) {
		WeatherCheck = FahrenheitToCelsius(ConvertedTemp);}
	else if (scale == 2) {
		WeatherCheck = ConvertedTemp; }
	else if (scale == 3) {
		WeatherCheck = KelvinToCelsius(ConvertedTemp); }

	//Output Messages
	printf("Converted Temperature: %.2f %c\n", ConvertedTemp, conversion);
	
	if (WeatherCheck < 0) {
	       printf("Freezing: Stay indoors.");}
	else if (WeatherCheck >=0 && WeatherCheck <= 10) {
	       printf("Cold: Wear heavy clothes."); }
	else if (WeatherCheck >= 10 && WeatherCheck <= 25) {
		printf("Comfortable: Wear light clothes."); }
	else if (WeatherCheck >= 25 && WeatherCheck <= 35) {
		printf("Hot: Wear extremely light clothes."); }
	else if (WeatherCheck > 35) {
		printf("Extreme Heat: Stay inside and turn on the AC."); }
	printf("\n");	
	return 0; }	
