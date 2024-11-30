import random
import subprocess
import argparse

def run_push_swap(numbers_count):
	numbers = random.sample(range(-1000, 1000), numbers_count)

	numbers_str = " ".join(map(str, numbers))

	command_append = f"./push_swap {numbers_str} > txt"
	command_count = f"./push_swap {numbers_str} | wc -l"

	subprocess.run(command_append, shell=True)
	result = subprocess.run(command_count, shell=True, stdout=subprocess.PIPE, text=True)

	print(f"\n\n\n{command_append}\n")
	print(f"\033[92mOperations: {int(result.stdout.strip().split()[0])}\033[0m\n\n\n")

if __name__ == "__main__":
	parser = argparse.ArgumentParser()
	parser.add_argument("numbers_count", type=int)

	args = parser.parse_args()
	run_push_swap(args.numbers_count)
