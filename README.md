# Fetch

Fetch libraries and interface for ReasonML/OCaml.

Fetch aims to provide a common interface over different HTTP and Promise-implementations in the ReasonML/OCaml ecosystem.

## [Fetch Core](./src/fetch-core)

Provides a functor for creating and providing your own Fetch-implementation. The goal is to be pluggable with any HTTP or Promise-implementation provided it conforms to the common interface.

## [Fetch Native Lwt](./src/fetch-native-lwt)

A consumable fetch-library for ReasonML/OCaml native. Uses `Lwt` for its `Promise`-implementation.

## Contributing

Feel free to open an issue and/or grabbing one of the [open issues](/issues).

## Contributors

All [contributors](https://github.com/lessp/reason-fetch/graphs/contributors), @ostera, @ulrikstrid.

## License

This project is licensed under the MIT License - see the [LICENSE](./LICENSE) file for details
