# PVM Course Material

## Downloading

Do **not** download it as a zip as you will not be able to get updates.

```bash
$ git clone https://github.com/UCLeuvenLimburg/pvm.git
```

## Getting updates

```bash
$ git pull
```

View the output to learn what files have been changed/added.

## Viewing what changes have been made

```bash
$ git diff --name-only @{'1 week ago'}
```

The `--name-only` option asks Git to only show file names, not the actual changes made.
You can drop it if you want a full diff.
