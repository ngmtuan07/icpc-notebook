mobius[1] = 1;
for (int i = 2; i < N; ++i) {
  --mobius[i];
  for (int j = i + i; j < N; j += i) mobius[j] -= mobius[i];
}