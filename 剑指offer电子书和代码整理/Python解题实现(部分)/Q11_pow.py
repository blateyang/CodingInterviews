# -*- coding:utf-8 -*-
class Solution:
    def Power(self, base, exponent):
        if abs(base-0.0) < 1e-6 and exponent < 0:
            return 0.0  # 0的负指数幂无效，返回0.0
        absExponent = abs(exponent)
        result = 1.0
        for i in range(absExponent):
            result *= base
        if exponent < 0:
            result = 1.0/result
        return result  # 包含规定的0^0=1.0