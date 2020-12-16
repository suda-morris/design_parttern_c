import os
import sys
import json

# The path of the file with the complete webhook event payload. For example, /github/workflow/event.json.
with open(os.environ['GITHUB_EVENT_PATH'], 'r') as f:
    event = json.load(f)
    json.dump(event, sys.stdout, indent=4)
