using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Programming_Practice
{
    class Algorithms
    {
        public int search(int[] a, int left, int right, int x)
        {
            int mid = (right - left) / 2;

            if (right < left)
                return -1;

            if (a[left] < a[mid])   // Left is normally ordered
            {
                if (x >= a[left] && x <= a[mid])
                    return search(a, left, mid - 1, x); // Search left
                else
                    return search(a, mid + 1, right, x);    // Search right
            }
            else if (a[mid] < a[left])
            {
                if (x >= a[mid] && x <= a[right])
                    return search(a, mid + 1, right, x);
                else
                    return search(a, left, mid - 1, x);
            }
            else if (a[left] == a[mid])
            {
                if (a[mid] != a[right])
                    return search(a, mid + 1, right, x);
                else
                {
                    int result = search(a, left, mid - 1, x);
                    if (result == -1)
                        return search(a, mid + 1, right, x);
                    else
                        return result;
                }
            }

            return -1;
        }
    }
}
