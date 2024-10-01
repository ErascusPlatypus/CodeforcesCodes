import os
import random
import subprocess
from datetime import datetime, timedelta

# Change this to the path where your "Codeforces" folder is located
REPO_PATH = "D:\Programming\Templates\CodeforcesCodes"

# Change this to your GitHub repository URL
GITHUB_REPO = "git@github.com:ErascusPlatypus/CodeforcesCodes.git"

# Move into the repository
os.chdir(REPO_PATH)

# Get list of all files in the Codeforces folder
all_files = [f for f in os.listdir(REPO_PATH) if os.path.isfile(f)]
random.shuffle(all_files)  # Shuffle to commit in random order

# Define commit date range: October 1, 2024 – January 31, 2025
start_date = datetime(2024, 10, 1)
end_date = datetime(2025, 1, 31)

# Generate commit dates (3-7 commits per day)
commit_dates = []
current_date = start_date

while current_date <= end_date:
    commits_today = random.randint(3, 7)  # Random commits per day
    for _ in range(commits_today):
        commit_time = current_date + timedelta(
            hours=random.randint(9, 23), minutes=random.randint(0, 59)
        )  # Random time in the day
        commit_dates.append(commit_time)
    current_date += timedelta(days=1)

# Sort dates in ascending order (oldest first)
commit_dates.sort()

# Start committing files
index = 0
for commit_time in commit_dates:
    if index >= len(all_files):  
        break  # Stop if all files are committed

    # Select 1–3 files to commit together
    num_files = random.randint(1, 3)
    files_to_commit = all_files[index : index + num_files]
    index += num_files  # Move index

    # Add files to Git
    subprocess.run(["git", "add"] + files_to_commit)

    # Format commit date
    commit_date_str = commit_time.strftime("%Y-%m-%d %H:%M:%S")
    env = {
        "GIT_COMMITTER_DATE": commit_date_str,
        "GIT_AUTHOR_DATE": commit_date_str,
    }

    # Make commit
    subprocess.run(
        ["git", "commit", "-m", f"Added {len(files_to_commit)} Codeforces solutions"],
        env=env,
    )

# Push changes to GitHub
subprocess.run(["git", "push", "origin", "main"])

print("All files committed with backdated timestamps and pushed successfully!")
