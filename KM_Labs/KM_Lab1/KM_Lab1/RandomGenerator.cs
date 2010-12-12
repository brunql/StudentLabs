using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace KM_Lab1
{
    public class RandomGenerator
    {
        public static List<double> randArr = new List<double>();
        public static int N
        {
            get
            {
                return randArr.Count;
            }
        }


        private static double lastNumber = 0;
        private static double M = 0;

        public static void Init(double _M)
        {
            lastNumber = Math.Pow(2, -64);
            M = _M;
            mx = -1;
        }

        public static double NextNumber
        {
            get
            {
                double result = lastNumber;
                lastNumber *= M;
                lastNumber -= Math.Truncate(lastNumber);
                return Math.Round(result, 4);
            }
        }


        public static void Fill(int length)
        {
            for (int i = 0; i < length; i++)
            {
                RandomGenerator.randArr.Add(RandomGenerator.NextNumber);
            }
            mx = -1;
        }


        private static double mx = -1;
        public static double Mx
        {
            get
            {
                if (mx == -1)
                {
                    mx = 0;
                    for (int i = 0; i < RandomGenerator.N; i++)
                    {
                        mx += randArr[i];
                    }
                    mx /= RandomGenerator.N;
                }
                return mx;
            }
        }

        private static double dx = -1;
        public static double Dx
        {
            get
            {
                if (dx == -1)
                {
                    dx = 0;
                    for (int i = 0; i < RandomGenerator.N; i++)
                    {
                        dx += Math.Pow(RandomGenerator.randArr[i] - Mx, 2);
                    }
                    dx /= RandomGenerator.N - 1;
                }
                return dx;
            }
        }





        public static double EvalMx(List<double> arr)
        {
            if (arr.Count == 0) return -1;

            double mx = 0;
            for (int i = 0; i < arr.Count; i++)
            {
                mx += arr[i];
            }
            mx /= arr.Count;
            return mx;
        }


        public static double EvalDx(List<double> arr, double mx)
        {
            double dx = 0;
            for (int i = 0; i < arr.Count; i++)
            {
                dx += Math.Pow(arr[i] - mx, 2);
            }
            dx /= arr.Count - 1;
            return dx;
        }
    }
}
