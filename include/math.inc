#if defined _math_methodmap_included
	#endinput
#endif
#define _math_methodmap_included

methodmap Math
{
// #region constants
	public static float e()
	{
		return 2.7182818284590452353602874713527;
	}
// #endregion
// #region variable methods
	public static any Abs(const any value, const bool isFloat = false)
	{
		if(isFloat)
		{
			float v = view_as<float>(value);
			return (v < 0.0 ? -v : v);
		}
		else
		{
			return (value < 0 ? -value : value);
		}
	}
	public static bool WithinRange(const any value, const any range, const bool isFloat = false)
	{
		if(isFloat)
		{
			float v = view_as<float>(value);
			return (Math.Abs(v, true) < view_as<float>(range) ? true : false);
		}
		else
		{
			return (Math.Abs(value) < range ? true : false);
		}
	}
	public static any Min(const any value, const any value2, const bool isFloat = false)
	{
		if(isFloat)
		{
			float v = view_as<float>(value);
			float v2 = view_as<float>(value2);
			return (v < v2) ? v : v2;
		}
		else
		{
			return (value < value2) ? value : value2;
		}
	}
	public static any Max(const any value, const any value2, const bool isFloat = false)
	{
		if(isFloat)
		{
			float v = view_as<float>(value);
			float v2 = view_as<float>(value2);
			return (v > v2) ? v : v2;
		}
		else
		{
			return (value > value2) ? value : value2;
		}
	}
// #endregion
// #region Standard methods
	public static float ArcCos(const any angle, const bool isFloat = true)
	{
		if(isFloat)
		{
			return ArcCosine(view_as<float>(angle));
		}
		else
		{
			return ArcCosine(float(angle));
		}
	}
	public static float ArcSin(const any angle, const bool isFloat = true)
	{
		if(isFloat)
		{
			return ArcSine(view_as<float>(angle));
		}
		else
		{
			return ArcSine(float(angle));
		}
	}
	public static float ArcTan(const any angle, const bool isFloat = true)
	{
		if(isFloat)
		{
			return ArcTangent(view_as<float>(angle));
		}
		else
		{
			return ArcTangent(float(angle));
		}
	}
	public static float Atan2(const any angle, const bool isFloat = true)
	{
		if(isFloat)
		{
			return ArcTangent2(view_as<float>(angle));
		}
		else
		{
			return ArcTangent2(float(angle));
		}
	}
	public static float Cos(const any angle, const bool isFloat = true)
	{
		if(isFloat)
		{
			return Cosine(view_as<float>(angle));
		}
		else
		{
			return Cosine(float(angle));
		}
	}
	public static float Exp(const any value, const bool isFloat = true)
	{
		if(isFloat)
		{
			return Exponential(view_as<float>(value));
		}
		else
		{
			return Exponential(float(value));
		}
	}
	public static float Log(const any value, const bool isFloat = true, const any base)
	{
		if(isFloat)
		{
			return Logarithm(view_as<float>(value), view_as<float>(base));
		}
		else
		{
			return Logarithm(float(value), float(base));
		}
	}
	public static float Sin(const any value, const bool isFloat = true)
	{
		if(isFloat)
		{
			return Sine(view_as<float>(value));
		}
		else
		{
			return Sine(float(value));
		}
	}
	public static float Sqrt(const any value, const bool isFloat = true)
	{
		if(isFloat)
		{
			return SquareRoot(view_as<float>(value));
		}
		else
		{
			return SquareRoot(float(value));
		}
	}
	public static float StandardDeviation(const any value, const bool isFloat = true)
	{
		if(isFloat)
		{
			return SquareRoot(view_as<float>(value));
		}
		else
		{
			return SquareRoot(float(value));
		}
	}
	public static float Tan(const any value, const bool isFloat = true)
	{
		if(isFloat)
		{
			return Tangent(view_as<float>(value));
		}
		else
		{
			return Tangent(float(value));
		}
	}
	public static float DegToRad(const any angle, const bool isFloat = true)
	{
		if(isFloat)
		{
			return DegToRad(view_as<float>(angle));
		}
		else
		{
			return DegToRad(float(angle));
		}
	}
	public static float RadToDeg(const any angle, const bool isFloat = true)
	{
		if(isFloat)
		{
			return RadToDeg(view_as<float>(angle));
		}
		else
		{
			return RadToDeg(float(angle));
		}
	}
	public static float Pow(const any value, const bool isFloat, const float exponent)
	{
		if(isFloat)
		{
			return Pow(view_as<float>(value), exponent);
		}
		else
		{
			return Pow(float(value), exponent);
		}
	}
	public static float Square(const any value, const bool isFloat = true)
	{
		return Math.Pow(value, isFloat, 2.0);
	}
// #endregion
// #region any[] methods
	public static int WithinStandardDeviation(const any[] samples, const int length, const float mean, const float deviation, const bool isFloat = true)
	{
		int count = 0;
		if(isFloat)
		{
			for (int i; i < length; i++)
			{
				float value = view_as<float>(samples[i]);
				if ( (Mean - deviation) < value < (mean + deviation) )
				{
					++count;
				}
			}
			return count;
		}
		else
		{
			for (int i; i < length; i++)
			{
				float value = float(samples[i]);
				if ( (Mean - deviation) < value < (mean + deviation) )
				{
					++count;
				}
			}
			return count;
		}
	}
	public static float Mean(const any[] arr, const int length, const bool isFloat = true)
	{
		float sum = 0.0;
		for (int i = 0; i < length; ++i)
		{
			if(isFloat)
			{
				sum += view_as<float>(arr[i]);
			}
			else
			{
				sum += float(arr[i]);
			}
		}
		return sum/length;
	}
	public static int Mode(const int[] samples, const int length)
	{
		int number = samples[0];
		int mode = samples[0];
		int count = 1;
		int countMode = 1;

		for (int i = 1; i < length; ++i)
		{
			if (samples[i] == number) 
			{
				++count;
			}
			else
			{
				if (count > countMode) 
				{
					countMode = count;
					mode = number;
				}
				count = 1;
				number = samples[i];
			}
		}
		return mode;
	}
	public static float SampleMean(const any[] samples, const int length, const bool isFloat = true)
	{
		float mean = 0.0;
		float m = 0.0;
		for (int i = 0; i < length; ++i)
		{
			if(isFloat)
			{
				mean += (view_as<float>(data[i]) - mean) / ++m;
			}
			else
			{
				mean += (float(data[i]) - mean) / ++m;
			}
		}
		return mean;
	}
	public static float SampleVariance(const any[] samples, const int length, const bool isFloat = true)
	{
		float variance = 0.0;
		if(isFloat)
		{
			float t = view_as<float>(samples[0]);
			for (int i = 1; i < length; i++)
			{
				t += view_as<float>(samples[i]);
				float diff = ((i + 1.0) * view_as<float>(samples[i])) - t;
				variance += (diff * diff)/( ( i + 1.0 ) * i);
			}

			return variance/float(length - 1);
		}
		else
		{
			float t = float(samples[0]);
			for (int i = 1; i < length; i++)
			{
				t += float(samples[i]);
				float diff = ((i + 1.0) * float(samples[i])) - t;
				variance += (diff * diff)/( ( i + 1.0 ) * i);
			}

			return variance/float(length - 1);
		}
	}
	public static float PopulationVariance(const any[] samples, const int length, const bool isFloat = true)
	{
		float mean = Math.Mean(samples, length, isFloat);
		if(isFloat)
		{
			float sum = 0.0;
			for (int i; i < length; i++)
			{
				sum += Pow(view_as<float>(samples[i]) - mean, 2.0);
			}
			return sum/length;
		}
		else
		{
			float sum = 0.0;
			for (int i; i < length; i++)
			{
				sum += Pow(float(samples[i]) - mean, 2.0);
			}
			return sum/length;
		}
	}
	public static float StandardPopulationDeviation(const any[] samples, const int length, const bool isFloat = true)
	{
		return SquareRoot(Math.PopulationVariance(samples, length, isFloat));
	}
	public static float StandardSampleDeviation(const any[] samples, const int length, const bool isFloat = true)
	{
		return SquareRoot(Math.SampleVariance(samples, length, isFloat));
	}
// #endregion
// #region arraylist methods
	public static float AMean(const ArrayList samples, const bool isFloat = true, const int block = 0)
	{
		float sum = 0.0;
		for (int i = 0; i < samples.Length; ++i)
		{
			if(isFloat)
			{
				sum += view_as<float>(samples.Get(i, block));
			}
			else
			{
				sum += float(samples.Get(i, block));
			}
		}
		return sum/float(samples.Length);
	}
	public static float ASampleMean(const ArrayList samples, const bool isFloat = true, const int block = 0)
	{
		float mean = 0.0;
		float m = 0.0;
		for (int i = 0; i < samples.Length; ++i)
		{
			if(isFloat)
			{
				mean += (view_as<float>(samples.Get(i, block)) - mean) / ++m;
			}
			else
			{
				mean += (float(samples.Get(i, block)) - mean) / ++m;
			}
		}
		return mean;
	}
	public static float ASampleVariance(const ArrayList samples, const bool isFloat = true, const int block = 0)
	{
		float variance = 0.0;
		if(isFloat)
		{
			float t = view_as<float>(samples.Get(0, block));
			for (int i = 1; i < samples.Length; i++)
			{
				t += view_as<float>(samples.Get(i));
				float diff = ((i + 1.0) * view_as<float>(samples.Get(i, block))) - t;
				variance += (diff * diff)/( ( i + 1.0 ) * i);
			}

			return variance/float(samples.Length - 1);
		}
		else
		{
			float t = float(samples.Get(0, block));
			for (int i = 1; i < samples.Length; i++)
			{
				t += float(samples.Get(i));
				float diff = ((i + 1.0) * float(samples.Get(i, block))) - t;
				variance += (diff * diff)/( ( i + 1.0 ) * i);
			}

			return variance/float(samples.Length - 1);
		}
	}
	public static float APopulationVariance(const ArrayList samples, const bool isFloat = true, const int block = 0)
	{
		float mean = Math.AMean(samples, isFloat);
		if(isFloat)
		{
			float sum = 0.0;
			for (int i = 0; i < samples.Length; i++)
			{
				sum += Pow(view_as<float>(samples.Get(i, block)) - mean, 2.0);
			}
			return sum/float(samples.Length);
		}
		else
		{
			float sum = 0.0;
			for (int i = 0; i < samples.Length; i++)
			{
				sum += Pow(float(samples.Get(i, block)) - mean, 2.0);
			}
			return sum/float(samples.Length);
		}
	}
	public static float AStandardPopulationDeviation(const ArrayList samples, const bool isFloat = true, const int block = 0)
	{
		return SquareRoot(Math.APopulationVariance(samples, isFloat, block));
	}
	public static int AWithinStandardDeviation(const ArrayList samples, const float mean,
												const float deviation, const bool isFloat = false, const int block = 0)
	{
		int count = 0;
		if(isFloat)
		{
			for (int i; i < samples.Length; i++)
			{
				float value = view_as<float>(samples.Get(i, block));
				if ( (mean - deviation) < value < (mean + deviation) )
				{
					++count;
				}
			}
			return count;
		}
		else
		{
			for (int i; i < samples.Length; i++)
			{
				float value = float(samples.Get(i, block));
				if ( (mean - deviation) < value < (mean + deviation) )
				{
					++count;
				}
			}
			return count;
		}
	}
	public static float ARelativeVariance(const ArrayList samples, const bool isFloat = true, const int block = 0)
	{
		if(isFloat)
		{
			float last = view_as<float>(samples.Get(0, block));
			float average = last
			for(int i = 1; i < samples.Length; ++i)
			{
				average += Math.Square(view_as<float>(samples.Get(i, block)) - last, true);
				last = view_as<float>(samples.Get(i, block));
			}
			average /= float(samples.Length);
			return average;
		}
		else
		{
			float last = float(samples.Get(0, block));
			float average = last;
			for(int i = 1; i < samples.Length; ++i)
			{
				average += Math.Square(float(samples.Get(i, block)) - last, true);
				last = float(samples.Get(i, block));
			}
			average /= float(samples.Length);
			return average;
		}
	}
// #endregion
// #region Trig methods
	/// <summary>
	/// Normalized Sinc function. sinc(x) = sin(pi*x)/(pi*x).
	/// </summary>
	public static float Sinc(const any x, const bool isFloat = true)
	{
		if(isFloat)
		{
			float z = FLOAT_PI * view_as<float>(x);
			return Sine(z) / z;
		}
		else
		{
			float z = FLOAT_PI * float(x);
			return Sine(z) / z;
		}
	}
	/// <summary>
	/// Trigonometric Cotangent of an angle in radian, or adjacent / opposite. Reciprocal of the tangent.
	/// </summary>
	/// <param name="radian">The angle in radian.</param>
	/// <returns>The cotangent of an angle in radian.</returns>
	public static float Cot(const any radian, const bool isFloat = true)
	{
		if(isFloat)
		{
			return 1.0 / Tangent(view_as<float>(radian));
		}
		else
		{
			return 1.0 / Tangent(float(radian));
		}
	}
	/// <summary>
	/// Trigonometric Secant of an angle in radian, or hypotenuse / adjacent. Reciprocal of the cosine.
	/// </summary>
	/// <param name="radian">The angle in radian.</param>
	/// <returns>The secant of the radian angle.</returns>
	public static float Sec(const any radian, const bool isFloat = true)
	{
		if(isFloat)
		{
			return 1.0 / Cosine(view_as<float>(radian));
		}
		else
		{
			return 1.0 / Cosine(float(radian));
		}
	}
	/// <summary>
	/// Trigonometric Cosecant of an angle in radian, or hypotenuse / opposite. Reciprocal of the sine.
	/// </summary>
	/// <param name="radian">The angle in radian.</param>
	/// <returns>Cosecant of an angle in radian.</returns>
	public static float Csc(const any radian, const bool isFloat = true)
	{
		if(isFloat)
		{
			return 1.0 / Sine(view_as<float>(radian));
		}
		else
		{
			return 1.0 / Sine(float(radian));
		}
	}
	/// <summary>
	/// Trigonometric principal Arc Cotangent in radian
	/// </summary>
	/// <param name="adjacent">The adjacent for a unit opposite (i.e. adjacent / opposite).</param>
	/// <returns>The angle in radian.</returns>
	public static float Acot(const any adjacent, const bool isFloat = true)
	{
		if(isFloat)
		{
			return ArcTangent(1.0 / view_as<float>(adjacent));
		}
		else
		{
			return ArcTangent(1.0 / float(adjacent));
		}
	}
	/// <summary>
	/// Trigonometric principal Arc Secant in radian
	/// </summary>
	/// <param name="hypotenuse">The hypotenuse for a unit adjacent (i.e. hypotenuse / adjacent).</param>
	/// <returns>The angle in radian.</returns>
	public static float Asec(const any hypotenuse, const bool isFloat = true)
	{
		if(isFloat)
		{
			return ArcCosine(1.0 / view_as<float>(hypotenuse));
		}
		else
		{
			return ArcCosine(1.0 / float(hypotenuse));
		}
	}
	/// <summary>
	/// Trigonometric principal Arc Cosecant in radian
	/// </summary>
	/// <param name="hypotenuse">The hypotenuse for a unit opposite (i.e. hypotenuse / opposite).</param>
	/// <returns>The angle in radian.</returns>
	public static float Acsc(const any hypotenuse, const bool isFloat = true)
	{
		if(isFloat)
		{
			return ArcSine(1.0 / view_as<float>(hypotenuse));
		}
		else
		{
			return ArcSine(1.0 / float(hypotenuse));
		}
	}
	/// <summary>
	/// Hyperbolic Sine
	/// </summary>
	/// <param name="angle">The hyperbolic angle, i.e. the area of the hyperbolic sector.</param>
	/// <returns>The hyperbolic sine of the angle.</returns>
	public static float Sinh(const any angle, const bool isFloat = true)
	{
		if(isFloat)
		{
			return (Exponential(view_as<float>(angle)) - Exponential(-view_as<float>(angle))) / 2.0;
		}
		else
		{
			return (Exponential(float(angle)) - Exponential(-float(angle))) / 2.0;
		}
	}	/// <summary>
	/// Hyperbolic Cosine
	/// </summary>
	/// <param name="angle">The hyperbolic angle, i.e. the area of the hyperbolic sector.</param>
	/// <returns>The hyperbolic Cosine of the angle.</returns>
	public static float Cosh(const any angle, const bool isFloat = true)
	{
		if(isFloat)
		{
			return (Exponential(view_as<float>(angle)) + Exponential(-view_as<float>(angle))) / 2.0;
		}
		else
		{
			return (Exponential(float(angle)) + Exponential(-float(angle))) / 2.0;
		}
	}
	/// <summary>
	/// Hyperbolic Tangent in radian
	/// </summary>
	/// <param name="angle">The hyperbolic angle, i.e. the area of the hyperbolic sector.</param>
	/// <returns>The hyperbolic tangent of the angle.</returns>
	public static float Tanh(const any angle, const bool isFloat = true)
	{
		if(isFloat)
		{
			if (view_as<float>(angle) > 19.1)
			{
				return 1.0;
			}

			if (view_as<float>(angle) < -19.1)
			{
				return -1.0;
			}

			float e1 = Exponential(view_as<float>(angle));
			float e2 = Exponential(-view_as<float>(angle));
			return (e1 - e2) / (e1 + e2);
		}
		else
		{
			if (float(angle) > 19.1)
			{
				return 1.0;
			}

			if (float(angle) < -19.1)
			{
				return -1.0;
			}

			float e1 = Exponential(float(angle));
			float e2 = Exponential(-float(angle));
			return (e1 - e2) / (e1 + e2);
		}
	}

	/// <summary>
	/// Hyperbolic Cotangent
	/// </summary>
	/// <param name="angle">The hyperbolic angle, i.e. the area of the hyperbolic sector.</param>
	/// <returns>The hyperbolic cotangent of the angle.</returns>
	public static float Coth(const any angle, const bool isFloat = true)
	{
		if(isFloat)
		{
			if (view_as<float>(angle) > 19.115)
			{
				return 1.0;
			}

			if (view_as<float>(angle) < -19.115)
			{
				return -1.0;
			}

			float e1 = Exponential(view_as<float>(angle));
			float e2 = Exponential(-view_as<float>(angle));
			return (e1 + e2) / (e1 - e2);
		}
		else
		{
			if (float(angle) > 19.115)
			{
				return 1.0;
			}

			if (float(angle) < -19.115)
			{
				return -1.0;
			}

			float e1 = Exponential(float(angle));
			float e2 = Exponential(-float(angle));
			return (e1 + e2) / (e1 - e2);
		}
	}
	/// <summary>
	/// Hyperbolic Secant
	/// </summary>
	/// <param name="angle">The hyperbolic angle, i.e. the area of the hyperbolic sector.</param>
	/// <returns>The hyperbolic secant of the angle.</returns>
	public static float Sech(const any angle, const bool isFloat = true)
	{
		return 1.0 / Math.Cosh(angle, isFloat);
	}
	/// <summary>
	/// Hyperbolic Cosecant
	/// </summary>
	/// <param name="angle">The hyperbolic angle, i.e. the area of the hyperbolic sector.</param>
	/// <returns>The hyperbolic cosecant of the angle.</returns>
	public static float Csch(const any angle, const bool isFloat = true)
	{
		return 1.0 / Math.Sinh(angle, isFloat);
	}
	/// Returns an integer that indicates the sign of a single-precision floating-point number.
	public static int Sign(const any value, const bool isFloat = true)
	{
		if(isFloat)
		{
			if(view_as<float>(value) < 0.0)
			{
				return -1;
			}
			else if(view_as<float>(value) > 0.0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			if(value < 0)
			{
				return -1;
			}
			else if(value > 0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}
	/// <summary>
	/// Hyperbolic Area Sine
	/// </summary>
	/// <param name="value">The real value.</param>
	/// <returns>The hyperbolic angle, i.e. the area of its hyperbolic sector.</returns>
	/* public static float Asinh(const any value, const bool isFloat = true)
	{
		// asinh(x) = Sign(x) * ln(|x| + sqrt(x*x + 1))
		// if |x| > huge, asinh(x) ~= Sign(x) * ln(2|x|)

		if(isFloat)
		{
			if (FloatAbs(view_as<float>(value)) >= 268435456.0) // 2^28, taken from freeBSD
			{
				return Math.Sign(view_as<float>(value), isFloat)
				 * (Math.Log(FloatAbs(view_as<float>(value)), true, Math.e())
				  + Math.Log(2.0, true, Math.e()));
			}

			return Math.Sign(value, isFloat) * Math.Log(FloatAbs(view_as<float>(value), true, Math.e())) + SquareRoot((view_as<float>(value) * view_as<float>(value)) + 1.0);
		}
		else
		{
			if (Math.Abs(value, .isFloat = false) >= 268435456) // 2^28, taken from freeBSD
			{
				return Math.Sign(float(value), true) * (Math.Log(FloatAbs(float(value)), true, Math.e()) + Math.Log(2, Math.e()));
			}

			return Math.Sign(value, isFloat) * Math.Log(FloatAbs(float(value), .isFloat = false, Math.e()) + SquareRoot((float(value) * float(value)) + 1.0));
		}
	} */
	/// <summary>
	/// Hyperbolic Area Cosine
	/// </summary>
	/// <param name="value">The real value.</param>
	/// <returns>The hyperbolic angle, i.e. the area of its hyperbolic sector.</returns>
	/* public static float Acosh(const any value, const bool isFloat = true)
	{
		// acosh(x) = ln(x + sqrt(x*x - 1))
		// if |x| >= 2^28, acosh(x) ~ ln(x) + ln(2)
		if(isFloat)
		{
			if (FloatAbs(view_as<float>(value)) >= 268435456.0) // 2^28, taken from freeBSD
			{
				return Logarithm((value)) + Logarithm(2.0);
			}

			return Logarithm(view_as<float>(value) + (SquareRoot(view_as<float>(value) - 1.0) * SquareRoot(view_as<float>(value) + 1.0)), Constants_E);
		}
		else
		{
			if (Math.abs(value, .isFloat = false)) >= 268435456.0) // 2^28, taken from freeBSD
			{
				return Logarithm(float(value)) + Logarithm(2.0);
			}

			return Logarithm(float(value) + (SquareRoot(float(value) - 1.0) * SquareRoot(float(value) + 1.0)), Constants_E);
		}
	} */
	/// <summary>
	/// Hyperbolic Area Tangent
	/// </summary>
	/// <param name="value">The real value.</param>
	/// <returns>The hyperbolic angle, i.e. the area of its hyperbolic sector.</returns>
	public static float Atanh(const any value, const bool isFloat = true)
	{
		if(isFloat)
		{
			return 0.5 * Logarithm((1.0 + view_as<float>(value)) / (1.0 - view_as<float>(value)), Constants_E);
		}
		else
		{
			return 0.5 * Logarithm((1.0 + float(value)) / (1.0 - float(value)), Constants_E);
		}
	}
	/// <summary>
	/// Hyperbolic Area Cotangent
	/// </summary>
	/// <param name="value">The real value.</param>
	/// <returns>The hyperbolic angle, i.e. the area of its hyperbolic sector.</returns>
	public static float Acoth(const any value, const bool isFloat = true)
	{
		if(isFloat)
		{
			return 0.5 * Logarithm((view_as<float>(value) + 1.0) / (view_as<float>(value) - 1.0), Constants_E);
		}
		else
		{
			return 0.5 * Logarithm((float(value) + 1.0) / (float(value) - 1.0), Constants_E);
		}
	}
	/// <summary>
	/// Hyperbolic Area Secant
	/// </summary>
	/// <param name="value">The real value.</param>
	/// <returns>The hyperbolic angle, i.e. the area of its hyperbolic sector.</returns>
	public static float Asech(const any value, const bool isFloat = true)
	{
		if(isFloat)
		{
			return Math.Acosh(1.0 / view_as<float>(value), true);
		}
		else
		{
			return Math.Acosh(1.0 / float(value), true);
		}
	}
	/// <summary>
	/// Hyperbolic Area Cosecant
	/// </summary>
	/// <param name="value">The real value.</param>
	/// <returns>The hyperbolic angle, i.e. the area of its hyperbolic sector.</returns>
	public static float Acsch(const any value, const bool isFloat = true)
	{
		if(isFloat)
		{
			return Math.Asinh(1.0 / view_as<float>(value));
		}
		else
		{
			return Math.Asinh(1.0 / float(value));
		}
	}
// #endregion
// #region Correlation Coefficient
	public static float PearsonCoefficient(const any[] x, const bool isXFloat, const any[] y, const bool isYFloat, int length)
	{
		float rawSumX, squaredSumX, rawSumY, squaredSumY, totalProduct;
		for(int i = 0; i < length; ++i)
		{
			float xi = isXFloat ? view_as<float>(x[i]) : float(x[i]);
			float yi = isYFloat ? view_as<float>(y[i]) : float(y[i]);
			rawSumX += xi;
			squaredSumX = Math.Square(xi, .isFloat = true));

			rawSumY += yi;
			squaredSumY = Math.Square(yi, .isFloat = true));

			totalProduct += (xi * yi);
		}


		float sumSquaredX = Math.Square(rawSumX, .isFloat = true);
		float sumSquaredY = Math.Square(rawSumY, .isFloat = true);
		float fLength = float(length);
		return (totalProduct - ((rawSumX * rawSumY) / fLength) /
				Math.Sqrt(squaredSumX - (sumSquaredX / fLength) ) * Math.Sqrt(squaredSumY - (sumSquaredY / fLength ) ) );
	}
	public static float APearsonCoefficient(const ArrayList x, const bool isXFloat, const int blockX, const ArrayList y, const bool isYFloat, const int blockY)
	{
		if(x.Length != y.Length)
		{
			return -2.0;
		}
		float rawSumX, squaredSumX, rawSumY, squaredSumY, totalProduct;
		for(int i = 0; i < x.Length; ++i)
		{
			float xi = isXFloat ? view_as<float>(x.Get(i, blockX)) : float(x.Get(i, blockX));
			float yi = isYFloat ? view_as<float>(y.Get(i, blockY)) : float(y.Get(i, blockY));
			rawSumX += xi;
			squaredSumX = Math.Square(xi, .isFloat = true);

			rawSumY += yi;
			squaredSumY = Math.Square(yi, .isFloat = true);

			totalProduct += (xi * yi);
		}


		float sumSquaredX = Math.Square(rawSumX, .isFloat = true);
		float sumSquaredY = Math.Square(rawSumY, .isFloat = true);
		float fLength = float(x.Length);
		return (totalProduct - ((rawSumX * rawSumY) / fLength) /
				Math.Sqrt(squaredSumX - (sumSquaredX / fLength) ) * Math.Sqrt(squaredSumY - (sumSquaredY / fLength ) ) );
	}
	public static float APearsonCoefficient2(const ArrayList x, const bool isXFloat, const int blockX, const ArrayList y, const bool isYFloat, const int blockY)
	{
		if(x.Length != y.Length || x.Length < 2)
		{
			return -2.0;
		}
		float sumX = 0.0, sumY = 0.0, sumXSqr = 0.0, sumYSqr = 0.0, sumProductXY = 0.0;

		for(int i = 0; i < x.Length; ++i)
		{
			float xi = isXFloat ? view_as<float>(x.Get(i, blockX)) : float(x.Get(i, blockX));
			float yi = isYFloat ? view_as<float>(y.Get(i, blockY)) : float(y.Get(i, blockY));
			sumX += xi;
			sumXSqr += xi * xi;
			sumY += yi;
			sumYSqr += yi * yi;
			sumProductXY += xi * yi;
		}

		float avgX = sumX / x.Length;
		float avgY = sumY / x.Length;

		return ( (sumProductXY / x.Length) - (avgX * avgY) ) /
			Math.Sqrt( ( (sumXSqr / x.Length) - (avgX * avgX) ) * ( (sumYSqr /x.Length) - (avgY * avgY) ) );
	}

	public static float APearsonCoefficient3(const ArrayList X, const bool isXFloat, const int blockX, const ArrayList Y, const bool isYFloat, const int blockY)
	{
		if(X.Length != Y.Length || X.Length < 2)
		{
			return -2.0;
		}
		float sumX, sumX2, sumY, sumY2, sumXY;
	
		int n = X.Length;
	
		for(int i = 0; i < X.Length; ++i)
		{
			float x = isXFloat ? view_as<float>(X.Get(i, blockX)) : float(X.Get(i, blockX));
			float y = isYFloat ? view_as<float>(Y.Get(i, blockY)) : float(Y.Get(i, blockY));
			sumX += x;
			sumX2 += x * x;
			sumY += y;
			sumY2 += y * y;
			sumXY += x * y;
		}
	
		float stdX = Math.Sqrt((sumX2 / n - sumX * sumX / n / n), true);
		float stdY = Math.Sqrt((sumY2 / n - sumY * sumY / n / n), true);
		float covariance = (sumXY / n - sumX * sumY / n / n);
	
		return covariance / stdX / stdY; 
	}
// #endregion
// #region Relative Variance
	public static float RelativeVariance(const any[] samples, const int length, const bool isFloat = true)
	{
		if(isFloat)
		{
			float last = view_as<float>(samples[0]);
			float average = last;
			for(int i = 1; i < length; ++i)
			{
				average += Math.Square(view_as<float>(samples[i]) - last, true);
				last = view_as<float>(samples[i]);
			}
			average /= float(length);
			return average;
		}
		else
		{
			float last = float(samples[0]);
			float average = last;
			for(int i = 1; i < length; ++i)
			{
				average += Math.Square(float(samples[i]) - last, true);
				last = float(samples[i]);
			}
			average /= float(length);
			return average;
		}
	}
// #endregion
}